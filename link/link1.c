/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:18:21 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:44:45 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_ass_links(t_holder *holder)
{
	holder->map->assets = holder->assets;
	holder->map->assets->game->assets = holder->assets;
	holder->map->assets->env_back->assets = holder->assets;
	holder->map->assets->player->assets = holder->assets;
	holder->map->assets->env_front->assets = holder->assets;
	holder->map->assets->exit->assets = holder->assets;
	holder->map->assets->colect->assets = holder->assets;
}

void	map_cord_links(t_holder *holder)
{
	holder->map->assets->exit->cord = holder->assets->exit->cord;
	holder->map->assets->player->cord = holder->assets->player->cord;
	holder->map->assets->colect->cord = holder->assets->colect->cord;
	holder->map->assets->env_back->cord = holder->assets->env_back->cord;
	holder->map->assets->env_front->cord = holder->assets->env_front->cord;
}

void	map_mlx_links(t_holder *holder, mlx_t *mlx)
{
	holder->map->assets->game->setup->mlx = mlx;
	holder->map->assets->env_back->setup->mlx = mlx;
	holder->map->assets->player->setup->mlx = mlx;
	holder->map->assets->env_front->setup->mlx = mlx;
	holder->map->assets->exit->setup->mlx = mlx;
	holder->map->assets->colect->setup->mlx = mlx;
}
