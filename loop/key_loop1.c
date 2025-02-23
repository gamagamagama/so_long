/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:08 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:58:34 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_bb_pl(t_wl_pl_bb *bb, int new_x, int new_y, t_game *player)
{
	bb->pl = (new_x - player->setup->data->vp_size_x / 2) + bb->of;
	bb->pr = (new_x + player->setup->data->vp_size_x / 2) - bb->of;
	bb->pt = (new_y - player->setup->data->vp_size_y / 2) + bb->of;
	bb->pb = (new_y + player->setup->data->vp_size_y / 2) - bb->of;
}

void	set_bb_wl(t_wl_pl_bb *bb, t_cord *wall, uint32_t wid, uint32_t hig)
{
	bb->wl = wall->cx * wid - wid / 3;
	bb->wr = wall->cx * wid + wid / 3;
	bb->wt = wall->cy * hig - hig / 3;
	bb->wb = wall->cy * hig + hig / 3;
}

bool	is_wsad(mlx_key_data_t keydata)
{
	return (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D);
}

bool	is_pressed(mlx_key_data_t keydata)
{
	return (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS);
}

bool	check_movement(t_game *player, int new_x, int new_y)
{
	t_cord		*wall;
	t_cord		*empty;
	t_wl_pl_bb	*bb;
	uint32_t	wid;
	uint32_t	hig;

	bb = init_bb();
	wid = player->assets->env_front->setup->img_env_front->width;
	hig = player->assets->env_front->setup->img_env_front->height;
	wall = player->assets->env_front->cord;
	empty = player->assets->env_back->cord;
	set_bb_pl(bb, new_x, new_y, player);
	while (wall != NULL && empty != NULL)
	{
		set_bb_wl(bb, wall, wid, hig);
		if (bb->pr > bb->wl && bb->pl < bb->wr
			&& bb->pb > bb->wt && bb->pt < bb->wb)
		{
			free(bb);
			return (false);
		}
		wall = wall->next;
	}
	free(bb);
	return (true);
}
