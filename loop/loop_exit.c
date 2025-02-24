/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:55:21 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 02:34:02 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wrapper(void *param)
{
	t_assets	*who;

	who = (t_assets *)param;
	time_hook(who->exit);
}

void	time_hook(void *param)
{
	t_game	*asset;

	asset = (t_game *)param;
	exit_animation(asset);
	update_viewport(asset);
}

void	exit_animation(t_game *who)
{
	static double	counter = 0;

	if ((counter < 10.0))
	{
		counter += 0.1;
		who->setup->complex->wave_freq += 0.1;
	}
	if (counter > 10.0)
		who->setup->complex->wave_freq -= 0.1;
	if (who->setup->complex->wave_freq <= 0.0)
		counter = 0.0;
}
