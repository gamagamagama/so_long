/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:32:24 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:31:48 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_grid(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	map->assets = NULL;
	if (map->grid)
	{
		while (i < map->rows)
		{
			if (map->grid[i])
			{
				free(map->grid[i]);
				map->grid[i] = NULL;
			}
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
}

void	free_map_vis(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	if (map->grid_visited)
	{
		while (i < map->rows)
		{
			if (map->grid_visited[i])
			{
				free(map->grid_visited[i]);
				map->grid_visited[i] = NULL;
			}
			i++;
		}
		free(map->grid_visited);
		map->grid_visited = NULL;
	}
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_map_grid(map);
	free_map_vis(map);
	free(map);
}
