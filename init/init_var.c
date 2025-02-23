/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:05:05 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:57:42 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vp_var(t_vp *vp)
{
	vp->vp_size = VIEWPORT_SIZE;
	vp->vp_position_x = (WINDOW_WIDTH - VIEWPORT_SIZE) / 2;
	vp->vp_position_y = (WINDOW_HEIGHT - VIEWPORT_SIZE) / 2;
	vp->vp_size_x = VIEWPORT_SIZE;
	vp->vp_size_y = VIEWPORT_SIZE;
	vp->next = NULL;
}

void	init_complex_var(t_complex_data *complex)
{
	complex->wave_amplitude = 10;
	complex->wave_freq = 3;
	complex->spiral_fact = 1;
	complex->depth = 1;
	complex->aa = 100;
	complex->bb = 100;
	complex->a = 3;
	complex->b = 2;
	complex->delta = M_PI / 4;
	complex->scale_fact = 0.1;
	complex->time = 0;
	complex->variable = 1;
}

void	init_graph_var(t_graph_data *graph)
{
	graph->delta_x = 0;
	graph->delta_y = 0;
	graph->end_x = 0;
	graph->end_y = 0;
	graph->start_x = 0;
	graph->start_y = 0;
	graph->step_x = 0;
	graph->step_y = 0;
	graph->pixel_x = 0;
	graph->pixel_y = 0;
	graph->thickness = 0;
	graph->error = 0;
	graph->color = 0x00000000;
}
