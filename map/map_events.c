/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:55:27 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:48:27 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_events(t_map *map)
{
	int	x;
	int	y;

	init_grid(map);
	init_visited(map);
	map->tmp_count = map->collectible_count;
	flood_fill(map->assets->player->cord->cx,
		map->assets->player->cord->cy, map);
	x = map->assets->exit->cord->cx;
	y = map->assets->exit->cord->cy;
	if (map->grid_visited[y][x] != '1' && map->tmp_count != 0)
		map->flood = 0;
	map->is_valid = (map->player_count == 1) && (map->collectible_count > 0)
		&& (map->exit_count == 1) && (map->walls == 1) && (map->rect == 1)
		&& (map->flood == 1);
}

int	init_grid(t_map *map)
{
	int	i;

	map->grid_visited = malloc(sizeof(char *) * map->rows);
	if (!map->grid_visited)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid_visited[i] = malloc(sizeof(char) * map->cols);
		if (!map->grid_visited[i])
			return (0);
		i++;
	}
	return (1);
}

static void	init_visited(t_map *map)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->rows)
	{
		k = 0;
		while (k < map->cols)
		{
			map->grid_visited[j][k] = '0';
			k++;
		}
		j++;
	}
}

static void	flood_fill(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->cols || y >= map->rows)
		return ;
	if (map->tmp_count == -1)
		map->tmp_count = map->collectible_count;
	if (map->grid[y][x] == '1' || map->grid_visited[y][x] == '1')
		return ;
	if (map->grid[y][x] == 'C' && map->grid_visited[y][x] == '0')
		map->tmp_count--;
	map->grid_visited[y][x] = '1';
	flood_fill(x + 1, y, map);
	flood_fill(x - 1, y, map);
	flood_fill(x, y + 1, map);
	flood_fill(x, y - 1, map);
}
