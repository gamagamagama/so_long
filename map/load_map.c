/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:57:47 by matus             #+#    #+#             */
/*   Updated: 2025/02/27 05:42:47 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mp_gr(t_map *map, int x, char *line)
{
	map->grid[x] = line;
	map->rows = x;
	map->cols = ft_strlen(line);
}

void	mp_gr_lst(t_map *map, int x)
{
	map->grid[x] = NULL;
	map->rows = x;
}

int	allocate_map_grid(char *path, t_map *map)
{
	int	nb_lines;

	nb_lines = count_lines(path);
	if (nb_lines <= 0)
		return (0);
	map->grid = malloc(sizeof(char *) * (nb_lines + 2));
	if (!map->grid)
	{
		print_malloc_err(MALOC_MAP_GRID);
		return (0);
	}
	return (1);
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
	else if (!allocate_map_grid(path, map))
	{
		print_error(MAP_NOT_PLAYABLE);
		close(fd);
		free_map_grid(map);
		free(map);
		exit(EXIT_FAILURE);
	}
	map = read_map_from_file(fd, map);
	close(fd);
	return (map);
}

int	line_check(int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd, 0);
	if (!line || ft_strlen(line) == 0 || line[0] == '\n')
	{
		get_next_line(-1, 1);
		free(line);
		close(fd);
		return (-1);
	}
	len = ft_strlen(line);
	free(line);
	return (len);
}
