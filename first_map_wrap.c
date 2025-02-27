/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map_wrap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:18:54 by matus             #+#    #+#             */
/*   Updated: 2025/02/27 05:33:20 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*first_map_wrap(t_map *map, char *path)
{
	if (!check_ber(path))
	{
		print_error(WRONG_FILE_EXT);
		return (NULL);
	}
	map = first_map(map);
	def_map(map);
	map = load_map(path, map);
	get_next_line(-1, 1);
	if (!map)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
