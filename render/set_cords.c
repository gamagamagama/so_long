/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:52:02 by matus             #+#    #+#             */
/*   Updated: 2025/02/27 01:53:46 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_env_back_cord(t_map *map, size_t i, size_t j)
{
	t_cord	*new_cord;

	new_cord = init_cord(&map->assets->env_back->cord);
	if (new_cord == NULL)
		return ;
	new_cord->cx = j;
	new_cord->cy = i;
}

void	set_collectible_cord(t_map *map, size_t i, size_t j, int *count)
{
	t_cord	*new_cord;

	new_cord = init_cord(&map->assets->colect->cord);
	if (new_cord == NULL)
		return ;
	new_cord->cx = j;
	new_cord->cy = i;
	(*count)--;
}

void	set_exit_cord(t_map *map, size_t i, size_t j)
{
	t_cord	*new_cord;

	new_cord = init_cord(&map->assets->exit->cord);
	if (new_cord == NULL)
		return ;
	new_cord->cx = j;
	new_cord->cy = i;
}

void	set_player_cord(t_map *map, size_t i, size_t j)
{
	t_cord	*new_cord;

	new_cord = init_cord(&map->assets->player->cord);
	if (new_cord == NULL)
		return ;
	new_cord->cx = j;
	new_cord->cy = i;
}

void	set_env_front_cord(t_map *map, size_t i, size_t j)
{
	t_cord	*new_cord;

	new_cord = init_cord(&map->assets->env_front->cord);
	if (new_cord == NULL)
		return ;
	new_cord->cx = j;
	new_cord->cy = i;
}
