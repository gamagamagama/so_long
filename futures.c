/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   futures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:04:34 by matus             #+#    #+#             */
/*   Updated: 2025/02/28 14:29:59 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    k_hook_n(t_game *who)
{
    if(who == who->assets->env_back)
        who->setup->graph->color = 0x7F0000FF;
    else if(who == who->assets->env_front)
        who->setup->graph->color = 0x777777FF;
    else if(who == who->assets->exit)
        who->setup->graph->color = 0xFF3FDFFF;
    else if(who == who->assets->colect)
        who->setup->graph->color = 0xFFFFFFFF;
    else if(who == who->assets->player)
        who->setup->graph->color = 0x00FF7FFF;
}
