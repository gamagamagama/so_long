/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:31 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 02:13:52 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_g_er(t_graph_data *g)
{
	if (g->start_x < g->end_x)
		g->step_x = 1;
	else
		g->step_x = -1;
	if (g->start_y < g->end_y)
		g->step_y = 1;
	else
		g->step_y = -1;
}

void	draw_thick_line(mlx_image_t *img, t_graph_data *g)
{
	int	e2;

	g->delta_x = abs(g->end_x - g->start_x);
	g->delta_y = abs(g->end_y - g->start_y);
	step_g_er(g);
	g->error = g->delta_x - g->delta_y;
	while (1)
	{
		draw_filled_square(img, g);
		if (g->start_x == g->end_x && g->start_y == g->end_y)
			break ;
		e2 = g->error * 2;
		if (e2 > -g->delta_y)
		{
			g->error -= g->delta_y;
			g->start_x += g->step_x;
		}
		if (e2 < g->delta_x)
		{
			g->error += g->delta_x;
			g->start_y += g->step_y;
		}
	}
}

void	draw_filled_square(mlx_image_t *img, t_graph_data *g)
{
	g->delta_y = -g->thickness;
	g->delta_x = -g->thickness;
	while (g->delta_y <= g->thickness)
	{
		g->delta_y++;
		while (g->delta_x <= g->thickness)
		{
			g->delta_x++;
			g->pixel_x = g->start_x + g->delta_x;
			g->pixel_y = g->start_y + g->delta_y;
			if (g->pixel_x >= 0 && (uint32_t)g->pixel_x < img->width
				&& g->pixel_y >= 0 && (uint32_t)g->pixel_y < img->height)
			{
				mlx_put_pixel(img, g->pixel_x, g->pixel_y, g->color);
			}
		}
	}
}

void	print_image_instances(mlx_image_t *image, t_game *a)
{
	int				j;
	size_t			i;
	mlx_instance_t	*instance;

	j = 0;
	if (!image || !image->instances || image->count == 0)
	{
		return ;
	}
	if (a == a->assets->colect)
	{
		j = a->setup->dep;
	}
	else if (a == a->assets->env_back)
	{
		j = a->setup->dep;
	}
	i = 0;
	while (i < image->count)
	{
		instance = &image->instances[i];
		instance->z = j;
		i++;
	}
}
