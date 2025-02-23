/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:27:46 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:49:08 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_wrapper(mlx_t *mlx, t_holder *holder, char *path)
{
	holder->map = init_map(mlx, holder->game, holder);
	holder->map = load_map(path, holder->map);
	map_checks(holder->map);
	check_walls(holder->map);
	if (holder->map->walls == 0 || holder->map->rect == 0)
	{
		free_map(holder->map);
		all_frees(mlx, holder);
		exit(EXIT_FAILURE);
	}
	find_exit_cords(holder->map);
	map_events(holder->map);
	holder->assets = holder->map->assets;
	holder->assets->map = holder->map;
	holder->map->assets = NULL;
}

t_map	*init_map(mlx_t *mlx, t_game *game, t_holder *holder)
{
	holder->assets = init_assets(mlx, holder->cord, holder->map, holder);
	holder->map = malloc(sizeof(t_map));
	if (holder->map == NULL)
	{
		perror("Failed to allocate memory for map");
		return (NULL);
	}
	map_ass_links(holder);
	map_cord_links(holder);
	map_mlx_links(holder, mlx);
	return (holder->map);
}
