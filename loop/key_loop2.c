/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_loop2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:41:52 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:58:42 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_end_wr(t_game *who, t_vp *vp)
{
	static int	thickness;

	thickness = 1;
	vp->vp_position_x = fmax(0, fmin(who->setup->data->vp_position_x,
				WINDOW_WIDTH - who->setup->data->vp_size));
	vp->vp_position_y = fmax(0, fmin(who->setup->data->vp_position_y,
				WINDOW_HEIGHT - who->setup->data->vp_size));
	check_tile(who, vp->vp_position_x, vp->vp_position_y);
	check_exit(who, vp->vp_position_x, vp->vp_position_y);
	update_viewport(who, thickness);
	static_viewport(who->assets->colect, thickness);
}

void	set_bb_pl_sec(t_wl_pl_bb *bb, int new_x, int new_y, t_game *player)
{
	bb->pl = (new_x - player->setup->data->vp_size_x / 2);
	bb->pr = (new_x + player->setup->data->vp_size_x / 2);
	bb->pt = (new_y - player->setup->data->vp_size_y / 2);
	bb->pb = (new_y + player->setup->data->vp_size_y / 2);
	bb->of = (player->setup->data->vp_size / 2) + 10;
}

void	check_exit(t_game *player, int new_x, int new_y)
{
	mlx_image_t	*exit_out;
	mlx_image_t	*colect;
	t_wl_pl_bb	*bb;
	int			i;

	bb = init_bb();
	colect = player->assets->colect->setup->img_collect;
	exit_out = player->assets->exit->setup->image;
	set_bb_pl_sec(bb, new_x, new_y, player);
	if (colect->count == 0)
	{
		i = 0;
		if (((bb->pr - bb->of > exit_out->instances[i].x - exit_out->width / 2)
				&& (bb->pl + bb->of < exit_out->instances[i].x + exit_out->width
					/ 2) && (bb->pb - bb->of > exit_out->instances[i].y
					- exit_out->height / 2) && (bb->pt
					+ bb->of < exit_out->instances[i].y + exit_out->height
					/ 2)))
		{
			free(bb);
			all_frees(player->setup->mlx, player->assets->holder);
			exit(EXIT_SUCCESS);
		}
	}
	free(bb);
}

void	check_tile(t_game *player, int new_x, int new_y)
{
	mlx_image_t	*colect;
	t_game		*colectable;
	t_wl_pl_bb	*bb;
	int			i;

	bb = init_bb();
	colect = player->assets->colect->setup->img_collect;
	colectable = player->assets->colect;
	set_bb_pl_sec(bb, new_x, new_y, player);
	i = 0;
	while (colect->count > i)
	{
		if ((bb->pr - bb->of > colect->instances[i].x - colect->width / 2)
			&& (bb->pl + bb->of < colect->instances[i].x + colect->width / 2)
			&& (bb->pb - bb->of > colect->instances[i].y - colect->height / 2)
			&& (bb->pt + bb->of < colect->instances[i].y + colect->height / 2)
			&& colect->instances[i].enabled == true)
		{
			colect_cords_right(colectable, i);
		}
		i++;
	}
	free(bb);
}
