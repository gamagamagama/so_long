/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:07:06 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 08:45:31 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*init_image(mlx_t *mlx)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (image == NULL)
	{
		perror("Error: failed to create image\n");
		return (NULL);
	}
	return (image);
}

t_vp	*init_viewport(void)
{
	t_vp	*vp;

	vp = malloc(sizeof(t_vp));
	if (vp == NULL)
	{
		perror("Failed to allocate memory for viewport");
		return (NULL);
	}
	init_vp_var(vp);
	return (vp);
}

t_complex_data	*init_complex_data(void)
{
	t_complex_data	*complex;

	complex = malloc(sizeof(t_complex_data));
	if (complex == NULL)
	{
		perror("Failed to allocate memory for complex data");
		return (NULL);
	}
	init_complex_var(complex);
	return (complex);
}

t_graph_data	*init_graph_data(void)
{
	t_graph_data	*graph;

	graph = malloc(sizeof(t_graph_data));
	if (graph == NULL)
	{
		perror("Failed to allocate memory for graph");
		return (NULL);
	}
	init_graph_var(graph);
	return (graph);
}

t_setup	*init_setup(t_holder *holder)
{
	holder->setup = malloc(sizeof(t_setup));
	if (holder->setup == NULL)
	{
		perror("Failed to allocate memory for setup");
		return (NULL);
	}
	holder->setup->data = init_viewport();
	holder->setup->complex = init_complex_data();
	holder->setup->graph = init_graph_data();
	holder->setup->mlx = holder->mlx;
	holder->setup->image = holder->image;
	holder->setup->img_collect = NULL;
	holder->setup->img_env_front = NULL;
	holder->setup->img_env_back = NULL;
	holder->setup->counteee = 0;
	holder->setup->dep = 0;
	return (holder->setup);
}
