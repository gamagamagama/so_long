/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customize1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:45:48 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 16:47:47 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	custumize_env_back(t_game *env_back)
{
	env_back->setup->complex->wave_amplitude = -170;
	env_back->setup->complex->wave_freq = 100.9;
	env_back->setup->complex->aa = 160;
	env_back->setup->complex->bb = -40;
	env_back->setup->complex->a = 9.6;
	env_back->setup->complex->b = 10.2;
	env_back->setup->complex->delta = 65.9;
	env_back->setup->complex->scale_fact = 0.3;
	env_back->setup->complex->spiral_fact = -19;
	env_back->setup->complex->depth = 6.6;
	env_back->setup->dep = 15;
	env_back->setup->data->vp_position_x = 0;
	env_back->setup->data->vp_position_y = 0;
	env_back->setup->graph->color = 0x7F0000FF;
}

void	custumize_env_front(t_game *env_front)
{
	env_front->setup->complex->wave_amplitude = -170;
	env_front->setup->complex->wave_freq = 39.9;
	env_front->setup->complex->aa = -160;
	env_front->setup->complex->bb = -40;
	env_front->setup->complex->a = 9.6;
	env_front->setup->complex->b = 10.2;
	env_front->setup->complex->delta = 65.9;
	env_front->setup->complex->scale_fact = 0.3;
	env_front->setup->complex->spiral_fact = -19;
	env_front->setup->complex->depth = 6.6;
	env_front->setup->dep = 15;
	env_front->setup->graph->color = 0x777777FF;
}

void	custumize_exit(t_game *exit)
{
	exit->setup->complex->wave_amplitude = 8;
	exit->setup->complex->variable = tan(exit->setup->complex->wave_freq)
		* M_PI;
	exit->setup->complex->wave_freq = 1.5;
	exit->setup->data->vp_position_x = 0;
	exit->setup->data->vp_position_y = 0;
	exit->setup->graph->color = 0xFF3FDFFF;
	exit->setup->dep = 42;
}

void	custumize_colect(t_game *colect)
{
	colect->setup->complex->wave_amplitude = 20;
	colect->setup->complex->wave_freq = 1.5;
	colect->setup->data->vp_position_x = 0;
	colect->setup->data->vp_position_y = 0;
	colect->setup->complex->delta = 13.1;
	colect->setup->graph->color = 0xFFFFFFFF;
	colect->setup->dep = 37;
}

void	custumize_player(t_game *player)
{
	player->setup->complex->variable = 1;
	player->setup->data->vp_position_x = 0;
	player->setup->data->vp_position_y = 0;
	player->setup->graph->color = 0x00FF7FFF;
	player->setup->dep = 51;
	player->setup->counteee = 0;
}
