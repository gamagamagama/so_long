/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:06:43 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 02:18:57 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_assets *assets)
{
	assets->env_back->setup->data->vp_position_x = assets->env_back->cord->cx
		* assets->env_back->setup->data->vp_size_x;
	assets->env_back->setup->data->vp_position_y = assets->env_back->cord->cy
		* assets->env_back->setup->data->vp_size_y;
	assets->env_front->setup->data->vp_position_x = assets->env_front->cord->cx
		* assets->env_front->setup->data->vp_size_x;
	assets->env_front->setup->data->vp_position_y = assets->env_front->cord->cy
		* assets->env_front->setup->data->vp_size_y;
	static_viewport(assets->colect);
	static_viewport(assets->env_front);
	static_viewport(assets->env_back);
	assets->player->setup->data->vp_position_x = assets->player->cord->cx
		* assets->player->setup->data->vp_size_x;
	assets->player->setup->data->vp_position_y = assets->player->cord->cy
		* assets->player->setup->data->vp_size_y;
	update_viewport(assets->player);
	assets->exit->setup->data->vp_position_x = assets->exit->cord->cx
		* assets->exit->setup->data->vp_size_x;
	assets->exit->setup->data->vp_position_y = assets->exit->cord->cy
		* assets->exit->setup->data->vp_size_y;
	update_viewport(assets->exit);
}

void	del_and_draw(t_game *asset)
{
	mlx_delete_image(asset->setup->mlx, asset->setup->image);
	asset->setup->image = mlx_new_image(asset->setup->mlx,
			asset->setup->data->vp_size, asset->setup->data->vp_size);
	draw_complex_pattern(asset, asset->setup->image, asset->setup->graph);
}

void	static_viewport(t_game *asset)
{
	if (!asset || !asset->setup || !asset->setup->image || !asset->setup->data)
		return ;
	if (asset->setup->image)
	{
		del_and_draw(asset);
	}
	if (asset == asset->assets->colect)
	{
		asset->setup->img_collect = asset->setup->image;
		ft_draw_collect(asset->setup->mlx, asset, asset->setup->img_collect,
			asset->cord);
	}
	if (asset == asset->assets->env_front)
	{
		asset->setup->img_env_front = asset->setup->image;
		ft_draw_collect(asset->setup->mlx, asset, asset->setup->img_env_front,
			asset->cord);
	}
	if (asset == asset->assets->env_back)
	{
		asset->setup->img_env_back = asset->setup->image;
		ft_draw_collect(asset->setup->mlx, asset, asset->setup->img_env_back,
			asset->cord);
	}
}

void	update_viewport(t_game *asset)
{
	t_graph_data	*g;

	g = asset->setup->graph;
	if (!asset || !asset->setup || !asset->setup->image || !asset->setup->data)
	{
		return ;
	}
	if (asset->setup->image)
		mlx_delete_image(asset->setup->mlx, asset->setup->image);
	asset->setup->image = mlx_new_image(asset->setup->mlx,
			asset->setup->data->vp_size, asset->setup->data->vp_size);
	if (!asset->setup->image)
	{
		return ;
	}
	draw_complex_pattern(asset, asset->setup->image, g);
	mlx_image_to_window(asset->setup->mlx, asset->setup->image,
		asset->setup->data->vp_position_x, asset->setup->data->vp_position_y);
}

mlx_image_t	*ft_draw_collect(mlx_t *mlx, t_game *asset, mlx_image_t *image,
		t_cord *cords)
{
	int		i;
	t_cord	*cord;
	int		new_x;
	int		new_y;

	i = 0;
	cord = cords;
	new_x = 0;
	new_y = 0;
	if (cord == NULL || image == NULL || mlx == NULL)
		return (NULL);
	while (cord != NULL)
	{
		if (!(cord->cx <= -1 && cord->cy <= -1))
		{
			new_x = (((cord->cx) * (image->height)));
			new_y = (((cord->cy) * (image->width)));
			mlx_image_to_window(mlx, image, (new_x), (new_y));
		}
		i++;
		cord = cord->next;
	}
	print_image_instances(image, asset);
	return (image);
}
