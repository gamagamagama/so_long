/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:16:31 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:44:29 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_links(t_holder *holder)
{
	holder->assets->game->assets = holder->assets;
	holder->assets->env_back->assets = holder->assets;
	holder->assets->player->assets = holder->assets;
	holder->assets->env_front->assets = holder->assets;
	holder->assets->exit->assets = holder->assets;
	holder->assets->colect->assets = holder->assets;
}

void	cord_links(t_holder *holder)
{
	holder->assets->exit->cord = holder->cord;
	holder->assets->player->cord = holder->cord;
	holder->assets->game->cord = holder->cord;
	holder->assets->env_back->cord = holder->cord;
	holder->assets->env_front->cord = holder->cord;
	holder->assets->colect->cord = holder->cord;
}

void	mlx_links(t_holder *holder)
{
	holder->assets->game->setup->mlx = holder->mlx;
	holder->assets->env_back->setup->mlx = holder->mlx;
	holder->assets->player->setup->mlx = holder->mlx;
	holder->assets->env_front->setup->mlx = holder->mlx;
	holder->assets->exit->setup->mlx = holder->mlx;
	holder->assets->colect->setup->mlx = holder->mlx;
}
