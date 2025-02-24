/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:09:31 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 03:45:38 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	*map;

	map = NULL;
	mlx = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s map_file\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!check_ber(argv[1]))
	{
		fprintf(stderr, "Invalid map file\n");
		return (EXIT_FAILURE);
	}
	map = first_map(map);
	map = load_map(argv[1], map);
	mlx = preset_mlx(mlx, map->cols * 50, map->rows * 50);
	free_map(map);
	init_structures(mlx, argv[1]);
	mlx_terminate(mlx);
	mlx = NULL;
	return (EXIT_SUCCESS);
}

int	check_ber(char *path)
{
	size_t	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'r' || path[i - 2] != 'e'
		|| path[i - 3] != 'b' || path[i - 4] != '.')
		return (0);
	return (1);
}

t_map	*first_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		perror("Failed to allocate memory for map");
		return (NULL);
	}
	return (map);
}

mlx_t	*preset_mlx(mlx_t *mlx, int32_t win_width, int32_t win_height)
{
	mlx = NULL;
	mlx = malloc(sizeof(mlx_t));
	if (!mlx)
		return (NULL);
	free(mlx);
	mlx = NULL;
	mlx = init_mlx_session(win_width, win_height, "Lost in Void");
	if (!mlx)
		return (NULL);
	return (mlx);
}

mlx_t	*init_mlx_session(int32_t width, int32_t height, char *title)
{
	mlx_t	*mlx;

	mlx = mlx_init(width, height, title, false);
	if (!mlx)
	{
		return (NULL);
	}
	return (mlx);
}
