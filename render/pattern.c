/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:30:18 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 02:15:37 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compute_end_x(int center_x, t_complex_data *c)
{
	return (center_x + (int)(c->scale_fact * ((c->aa + c->time * c->spiral_fact)
			* sin(c->a * c->time + c->delta) + c->wave_amplitude
			* sin(c->wave_freq * c->time) * c->variable)));
}

int	compute_end_y(int center_y, t_complex_data *c)
{
	return (center_y + (int)(c->scale_fact * ((c->bb + c->time * c->spiral_fact)
			* cos(c->b * c->time) + c->wave_amplitude
			* cos(c->wave_freq * c->time) * c->variable)));
}

void	dcp_end(t_graph_data *g, t_complex_data *c)
{
	c->time += 0.05;
	g->start_x = g->end_x;
	g->start_y = g->end_y;
}

void	draw_complex_pattern(t_game *asset, mlx_image_t *img, t_graph_data *g)
{
	t_assets		*ass;
	t_complex_data	*c;
	int				center_x;
	int				center_y;

	ass = asset->assets;
	c = asset->setup->complex;
	center_x = (asset->setup->data->vp_size / 2);
	center_y = (asset->setup->data->vp_size / 2);
	g->start_x = center_x;
	g->start_y = center_y;
	recompute_c_variable(c, ass, asset);
	c->time = 0;
	while (c->time < (2 * M_PI * c->depth))
	{
		g->end_x = compute_end_x(center_x, c);
		g->end_y = compute_end_y(center_y, c);
		if (g->end_x >= 0 && g->end_x < (int)img->width && g->end_y >= 0
			&& g->end_y < (int)img->height)
		{
			draw_thick_line(img, g);
		}
		dcp_end(g, c);
	}
}

void	recompute_c_variable(t_complex_data *c, t_assets *asset, t_game *ass)
{
	if (!(ass || c))
	{
		free(c);
		free(ass);
		exit(EXIT_FAILURE);
	}
	if (ass == asset->exit)
	{
		c->variable = tan(c->wave_freq) * M_PI;
	}
	else
		c->variable = 1;
}
