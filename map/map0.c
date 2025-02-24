/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:27:46 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 09:01:13 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_wrapper(mlx_t *mlx, t_holder *holder, char *path)
{
	holder->map = init_map(mlx, holder);
	holder->map = load_map(path, holder->map);
	map_checks(holder->map);
	if (holder->map->player_count != 1 || holder->map->exit_count != 1
		|| holder->map->collectible_count < 1)
	{
		perror("Invalid count of player, colectable or exit");
		map_frai(mlx, holder);
	}
	check_walls(holder->map);
	if (holder->map->walls == 0 || holder->map->rect == 0)
	{
		perror("Map is not surrounded by walls or is not rectangle");
		map_frai(mlx, holder);
	}
	find_exit_cords(holder->map);
	map_events(holder->map);
	holder->assets = holder->map->assets;
	holder->assets->map = holder->map;
	holder->map->assets = NULL;
}

t_map	*init_map(mlx_t *mlx, t_holder *holder)
{
	holder->assets = init_assets(mlx, holder);
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
