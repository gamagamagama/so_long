/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:57:47 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 12:26:49 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mp_gr(t_map *map, int x, char *line)
{
	map->grid[x] = line;
	map->rows = x;
	map->cols = ft_strlen(line) - 1;
}

void	mp_gr_lst(t_map *map, int x)
{
	map->grid[x] = NULL;
	map->rows = x;
	map->cols += 1;
}

t_map	*allocate_map_grid(char *path, t_map *map)
{
	int	nb_lines;

	nb_lines = count_lines(path);
	if (nb_lines <= 0)
		return (NULL);
	def_map(map);
	map->grid = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map->grid)
	{
		print_malloc_err(MALOC_MAP_GRID);
		return (NULL);
	}
	return (map);
}

t_map	*load_map(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error(MAP_NOT_FOUND);
		close(fd);
		free(map);
		exit(EXIT_FAILURE);
	}
	if (!allocate_map_grid(path, map))
	{
		print_error(MAP_NOT_PLAYABLE);
		close(fd);
		free(map);
		exit(EXIT_FAILURE);
	}
	map = read_map_from_file(fd, map);
	close(fd);
	return (map);
}

int	count_lines(const char *path)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
			lines++;
		free(line);
	}
	close(fd);
	return (lines);
}
