/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:20:31 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:33:23 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_frees(mlx_t *mlx, t_holder *holder)
{
	mlx_delete_image(mlx, holder->image);
	holder->image = NULL;
	wrapper_free_cord(holder);
	wrapper_free_colect(mlx, holder);
	wrapper_free_player(mlx, holder);
	wrapper_free_env_back(mlx, holder);
	wrapper_free_exit(mlx, holder);
	wrapper_free_env_front(mlx, holder);
	wrapper_free_game(mlx, holder);
	wrapper_null(holder);
	free(holder->assets);
	holder->assets = NULL;
	free(holder);
	holder = NULL;
	mlx_terminate(mlx);
	mlx = NULL;
}

void	wrapper_free_cord(t_holder *holder)
{
	free_cord(holder->assets->player->cord);
	holder->assets->player->cord = NULL;
	free_cord(holder->assets->colect->cord);
	holder->assets->colect->cord = NULL;
	free_cord(holder->assets->exit->cord);
	holder->assets->exit->cord = NULL;
	free_cord(holder->assets->env_back->cord);
	holder->assets->env_back->cord = NULL;
	free_cord(holder->assets->env_front->cord);
	holder->assets->env_front->cord = NULL;
}

void	wrapper_free_colect(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->colect->setup->complex);
	holder->assets->colect->setup->complex = NULL;
	free(holder->assets->colect->setup->data);
	holder->assets->colect->setup->data = NULL;
	free(holder->assets->colect->setup->graph);
	holder->assets->colect->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->colect->setup->image);
	holder->assets->colect->setup->image = NULL;
	mlx_delete_image(mlx, holder->assets->colect->setup->img_collect);
	holder->assets->colect->setup->img_collect = NULL;
	holder->assets->colect->setup->mlx = NULL;
	holder->assets->colect->assets = NULL;
	free(holder->assets->colect->setup);
	holder->assets->colect->setup = NULL;
	free(holder->assets->colect);
	holder->assets->colect = NULL;
}

void	wrapper_free_player(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->player->setup->complex);
	holder->assets->player->setup->complex = NULL;
	free(holder->assets->player->setup->data);
	holder->assets->player->setup->data = NULL;
	free(holder->assets->player->setup->graph);
	holder->assets->player->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->player->setup->image);
	holder->assets->player->setup->image = NULL;
	holder->assets->player->setup->mlx = NULL;
	holder->assets->player->assets = NULL;
	free(holder->assets->player->setup);
	holder->assets->player->setup = NULL;
	free(holder->assets->player);
	holder->assets->player = NULL;
}

void	wrapper_free_env_back(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->env_back->setup->complex);
	holder->assets->env_back->setup->complex = NULL;
	free(holder->assets->env_back->setup->data);
	holder->assets->env_back->setup->data = NULL;
	free(holder->assets->env_back->setup->graph);
	holder->assets->env_back->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->env_back->setup->image);
	holder->assets->env_back->setup->image = NULL;
	holder->assets->env_back->setup->mlx = NULL;
	mlx_delete_image(mlx, holder->assets->env_back->setup->img_env_back);
	holder->assets->env_back->setup->img_env_back = NULL;
	holder->assets->env_back->assets = NULL;
	free(holder->assets->env_back->setup);
	holder->assets->env_back->setup = NULL;
	free(holder->assets->env_back);
	holder->assets->env_back = NULL;
}
