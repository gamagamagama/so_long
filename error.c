/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 05:30:18 by matus             #+#    #+#             */
/*   Updated: 2025/02/24 09:11:20 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(t_error error)
{
	if (error == USAGE)
		perror("Usage: ./so_long map_file/map.ber");
    if (error == WRONG_FILE_EXT)
        perror("Invalid map file extension");
    if (error == MALOC_MAP)
        perror("Failed to allocate memory for map");
    if (error == MAP_NOT_FOUND)
        perror("Map file not found");
    if (error == MALOC_MAP_GRID)
        perror("Failed to allocate memory for map grid");
    if (error == MALOC_MLX)
        perror("Failed to allocate memory for mlx");
    if (error == MALOC_HOLDER)
        perror("Failed to allocate memory for holder");
    if (error == MAP_CHAR)
        perror("Invalid map character");
    if (error == MAP_NOT_FLOOD)
        perror("Map is not flood filled");
    if (error == MAP_NOT_PLAYABLE)
        perror("Map is not valid not playable");

}

void	cord_ass_link_n(t_holder *holder)
{
	holder->assets->game->cord = NULL;
	holder->assets->colect->cord = NULL;
	holder->assets->player->cord = NULL;
	holder->assets->env_back->cord = NULL;
	holder->assets->env_front->cord = NULL;
	holder->assets->exit->cord = NULL;
}
void    map_frai(mlx_t *mlx, t_holder *holder)
{
    free_map(holder->map);
	all_frees(mlx, holder);
	exit(EXIT_FAILURE);
}
