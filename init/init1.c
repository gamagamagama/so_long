/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:09:41 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 01:33:40 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cord	*init_cord(t_cord **cord)
{
	t_cord	*new_cord;

	new_cord = NULL;
	if (!cord)
		return (NULL);
	new_cord = malloc(sizeof(t_cord));
	if (!new_cord)
	{
		perror("Failed to allocate memory for cord");
		return (NULL);
	}
	new_cord->next = NULL;
	new_cord->cx = -1;
	new_cord->cy = -1;
	if (*cord)
		new_cord->next = *cord;
	*cord = new_cord;
	return (new_cord);
}

t_game	*init_game(mlx_t *mlx, t_holder *holder)
{
	holder->game = malloc(sizeof(t_game));
	if (holder->game == NULL)
	{
		perror("Failed to allocate memory for game");
		return (NULL);
	}
	holder->image = init_image(mlx);
	holder->setup = init_setup(holder);
	holder->complex = holder->setup->complex;
	holder->graph = holder->setup->graph;
	holder->vp = holder->setup->data;
	holder->game->setup = holder->setup;
	holder->game->cord = holder->cord;
	return (holder->game);
}

t_assets	*init_assets(mlx_t *mlx, t_holder *holder)
{
	init_game(mlx, holder);
	holder->assets = malloc(sizeof(t_assets));
	holder->assets->holder = holder;
	holder->assets->count = 0;
	holder->assets->map = holder->map;
	holder->assets->game = holder->game;
	holder->assets->game->cord = NULL;
	holder->assets->colect = init_game(mlx, holder);
	holder->assets->colect->cord = NULL;
	holder->assets->player = init_game(mlx, holder);
	holder->assets->player->cord = NULL;
	holder->assets->env_back = init_game(mlx, holder);
	holder->assets->env_back->cord = NULL;
	holder->assets->env_front = init_game(mlx, holder);
	holder->assets->env_front->cord = NULL;
	holder->assets->exit = init_game(mlx, holder);
	holder->assets->exit->cord = NULL;
	assets_links(holder);
	cord_links(holder);
	mlx_links(holder);
	custumizer_pass(holder->assets);
	return (holder->assets);
}

t_holder	*init_holder(t_holder **holder)
{
	*holder = malloc(sizeof(t_holder));
	if (*holder == NULL)
	{
		perror("Failed to allocate memory for holder");
		return (NULL);
	}
	null_holder(*holder);
	return (*holder);
}

t_wl_pl_bb	*init_bb(void)
{
	t_wl_pl_bb	*bb;

	bb = malloc(sizeof(t_wl_pl_bb));
	if (!bb)
		return (NULL);
	bb->wl = 0;
	bb->wr = 0;
	bb->wt = 0;
	bb->wb = 0;
	bb->pl = 0;
	bb->pr = 0;
	bb->pt = 0;
	bb->pb = 0;
	bb->of = 5;
	return (bb);
}
