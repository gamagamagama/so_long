/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:03:55 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 14:03:32 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	event_handler(mlx_key_data_t keydata, void *param)
{
	t_assets	*who;

	who = (t_assets *)param;
	key_hook(keydata, who->player);
	key_hooker_back(keydata, who->env_back);
	key_hooker_back(keydata, who->env_front);
	key_hooker_back(keydata, who->colect);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*who;
	int		new_x;
	int		new_y;
	int		wa;

	who = (t_game *)param;
	new_x = who->setup->data->vp_position_x;
	new_y = who->setup->data->vp_position_y;
	wa = who->setup->complex->wave_amplitude;
	key_sw(keydata, &new_y, &wa);
	key_da(keydata, &new_x, who->setup->complex);
	key_esc(who, keydata);
	if (is_wsad(keydata) && check_movement(who, new_x, new_y)
		&& is_pressed(keydata))
	{
		who->setup->data->vp_position_x = new_x;
		who->setup->data->vp_position_y = new_y;
		who->setup->complex->wave_amplitude = wa;
		who->setup->counteee += 1;
		fprintf(stderr, "%ld\n", who->setup->counteee);
	}
	key_hook_end_wr(who, who->setup->data);
}

void	key_sw(mlx_key_data_t keydata, int *new_y, int *wa)
{
	if (keydata.key == MLX_KEY_S)
	{
		*new_y += 4;
		*wa += 2;
	}
	else if (keydata.key == MLX_KEY_W)
	{
		*new_y -= 4;
		*wa -= 2;
	}
}

void	key_da(mlx_key_data_t keydata, int *new_x, t_complex_data *c)
{
	if (keydata.key == MLX_KEY_D)
	{
		c->wave_freq += 0.2;
		*new_x += 4;
	}
	else if (keydata.key == MLX_KEY_A)
	{
		c->wave_freq -= 0.2;
		*new_x -= 4;
	}
}

void	key_esc(t_game *who, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		all_frees(who->setup->mlx, who->assets->holder);
		exit(EXIT_SUCCESS);
	}
	else if (keydata.key == MLX_KEY_M)
	{
		k_hook_m(who->assets->exit->setup->graph);
		k_hook_m(who->setup->graph);
	}
}
