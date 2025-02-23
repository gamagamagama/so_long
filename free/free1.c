/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:23:59 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:34:15 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wrapper_free_exit(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->exit->setup->complex);
	holder->assets->exit->setup->complex = NULL;
	free(holder->assets->exit->setup->data);
	holder->assets->exit->setup->data = NULL;
	free(holder->assets->exit->setup->graph);
	holder->assets->exit->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->exit->setup->image);
	holder->assets->exit->setup->image = NULL;
	holder->assets->exit->setup->mlx = NULL;
	free(holder->assets->exit->setup);
	holder->assets->exit->setup = NULL;
	free(holder->assets->exit);
	holder->assets->exit = NULL;
}

void	wrapper_free_env_front(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->env_front->setup->complex);
	holder->assets->env_front->setup->complex = NULL;
	free(holder->assets->env_front->setup->data);
	holder->assets->env_front->setup->data = NULL;
	free(holder->assets->env_front->setup->graph);
	holder->assets->env_front->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->env_front->setup->image);
	holder->assets->env_front->setup->image = NULL;
	holder->assets->env_front->setup->mlx = NULL;
	mlx_delete_image(mlx, holder->assets->env_front->setup->img_env_front);
	holder->assets->env_front->setup->img_env_front = NULL;
	holder->assets->env_front->assets = NULL;
	free(holder->assets->env_front->setup);
	holder->assets->env_front->setup = NULL;
	free(holder->assets->env_front);
	holder->assets->env_front = NULL;
}

void	wrapper_free_game(mlx_t *mlx, t_holder *holder)
{
	free(holder->assets->game->setup->complex);
	holder->assets->game->setup->complex = NULL;
	free(holder->assets->game->setup->data);
	holder->assets->game->setup->data = NULL;
	free(holder->assets->game->setup->graph);
	holder->assets->game->setup->graph = NULL;
	mlx_delete_image(mlx, holder->assets->game->setup->image);
	holder->assets->game->setup->image = NULL;
	holder->assets->game->setup->mlx = NULL;
	holder->assets->game->assets = NULL;
	free(holder->assets->game->setup);
	holder->assets->game->setup = NULL;
	free(holder->assets->game);
	holder->assets->game = NULL;
}

void	wrapper_null(t_holder *holder)
{
	holder->assets->exit = NULL;
	holder->assets->holder = NULL;
	holder->mlx = NULL;
	holder->vp = NULL;
	holder->complex = NULL;
	holder->graph = NULL;
	holder->setup = NULL;
	holder->cord = NULL;
	holder->game = NULL;
}

void	free_cord(t_cord *cord)
{
	t_cord	*tmp;

	while (cord)
	{
		tmp = cord;
		cord = cord->next;
		free(tmp);
		tmp = NULL;
	}
}
