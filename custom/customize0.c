/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:43:46 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:27:48 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	custumizer_pass(t_assets *assets)
{
	customizer(assets->game, assets);
	customizer(assets->env_back, assets);
	customizer(assets->player, assets);
	customizer(assets->env_front, assets);
	customizer(assets->exit, assets);
	customizer(assets->colect, assets);
}

void	customizer(t_game *aset, t_assets *assets)
{
	if (aset == assets->game)
		custumize_game(assets->game);
	else if (aset == assets->env_back)
		custumize_env_back(assets->env_back);
	else if (aset == assets->player)
		custumize_player(assets->player);
	else if (aset == assets->env_front)
		custumize_env_front(assets->env_front);
	else if (aset == assets->exit)
		custumize_exit(assets->exit);
	else if (aset == assets->colect)
		custumize_colect(assets->colect);
	else
		return ;
}

void	custumize_game(t_game *game)
{
	game->setup->complex->wave_amplitude = 10;
	game->setup->complex->variable = tan(game->setup->complex->wave_freq)
		* M_PI;
	game->setup->complex->wave_freq = 1.8;
	game->setup->data->vp_position_x = 0;
	game->setup->data->vp_position_y = 0;
	game->setup->graph->color = 0x0000FFFF;
}
