/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:05:42 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:48:01 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	er_mp_chck(t_map *map, size_t i, size_t j)
{
	if (map->grid[i][j] != '1' && map->grid[i][j] != '0'
		&& map->grid[i][j] != 'P' && map->grid[i][j] != 'C'
		&& map->grid[i][j] != 'E')
	{
		all_frees(map->assets->holder->mlx, map->assets->holder);
		exit(EXIT_FAILURE);
	}
}

void	map_checks(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->grid[i][j] == 'P')
				map->player_count++;
			else if (map->grid[i][j] == 'C')
				map->collectible_count++;
			else if (map->grid[i][j] == 'E')
				map->exit_count++;
			er_mp_chck(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->cols)
	{
		if (map->grid[0][j] != '1' || map->grid[map->rows - 1][j] != '1')
		{
			map->walls = 0;
		}
		j++;
	}
	i = 0;
	while (i < map->rows)
	{
		if ((ft_strlen(map->grid[i])) != map->cols)
		{
			map->rect = 0;
		}
		if (map->grid[i][0] != '1' || map->grid[i][map->cols - 1] != '1')
		{
			map->walls = 0;
		}
		i++;
	}
}

void	find_exit_cords(t_map *map)
{
	int		count;
	size_t	i;
	size_t	j;

	count = map->collectible_count;
	i = 0;
	while (i < map->rows && count >= 0)
	{
		j = 0;
		while (j < map->cols && count >= 0)
		{
			if (map->grid[i][j] != '1')
				set_env_back_cord(map, i, j);
			if (map->grid[i][j] == 'C')
				set_collectible_cord(map, i, j, &count);
			else if (map->grid[i][j] == 'E')
				set_exit_cord(map, i, j);
			else if (map->grid[i][j] == 'P')
				set_player_cord(map, i, j);
			else if (map->grid[i][j] == '1')
				set_env_front_cord(map, i, j);
			j++;
		}
		i++;
	}
}
