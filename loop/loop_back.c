/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:29:10 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 02:33:48 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	k_hook_b_w(t_complex_data *c)
{
	c->b += 0.1;
	c->delta += 1.0;
}

void	k_hook_b_s(t_complex_data *c)
{
	c->b -= 0.1;
	c->delta -= 1.0;
}

void	k_hook_b_a(t_complex_data *c)
{
	c->a += 0.1;
	c->delta += 1.0;
}

void	k_hook_b_d(t_complex_data *c)
{
	c->a -= 0.1;
	c->delta -= 1.0;
}

void	key_hooker_back(mlx_key_data_t keydata, void *param)
{
	t_game			*who;
	t_complex_data	*c;

	who = (t_game *)param;
	c = who->setup->complex;
	if (keydata.key == MLX_KEY_W)
		k_hook_b_w(c);
	if (keydata.key == MLX_KEY_S)
		k_hook_b_s(c);
	if (keydata.key == MLX_KEY_A)
		k_hook_b_a(c);
	if (keydata.key == MLX_KEY_D)
		k_hook_b_d(c);
	static_viewport(who);
}
