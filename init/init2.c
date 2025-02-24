/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:13:49 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 09:11:09 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_structures(mlx_t *mlx, char *path)
{
	t_holder	*holder;

	holder = NULL;
	holder = init_holder(&holder);
	holder->mlx = mlx;
	map_wrapper(mlx, holder, path);
	if (holder->map->is_valid)
	{
		free_map(holder->map);
		holder->map = NULL;
		holder->assets->map = holder->map;
		render(holder->assets);
		mlx_loop_hook(mlx, wrapper, holder->assets);
		mlx_key_hook(mlx, event_handler, holder->assets);
		mlx_loop(mlx);
		all_frees(mlx, holder);
		exit(EXIT_SUCCESS);
	}
	print_error(MAP_NOT_PLAYABLE);
	free_map(holder->map);
	holder->map = NULL;
	holder->assets->map = holder->map;
	all_frees(mlx, holder);
	exit(EXIT_FAILURE);
}

void	null_holder(t_holder *holder)
{
	holder->mlx = NULL;
	holder->image = NULL;
	holder->vp = NULL;
	holder->complex = NULL;
	holder->graph = NULL;
	holder->setup = NULL;
	holder->cord = NULL;
	holder->game = NULL;
	holder->assets = NULL;
	holder->map = NULL;
}

void	def_map(t_map *map)
{
	map->grid = NULL;
	map->grid_visited = NULL;
	map->rows = 0;
	map->cols = 0;
	map->player_count = 0;
	map->collectible_count = 0;
	map->tmp_count = -1;
	map->exit_count = 0;
	map->flood = 1;
	map->walls = 1;
	map->rect = 1;
	map->cord_x = 0;
	map->cord_y = 0;
	map->is_valid = false;
}
