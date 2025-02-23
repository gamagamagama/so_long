/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:09:31 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 23:10:41 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	*map;

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
