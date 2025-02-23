/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:25:38 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:34:50 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(char *result, int c)
{
	int	i;

	i = 0;
	if (!result)
		return (0);
	if (c == '\0')
		return ((char *)&result[ft_strlen(result)]);
	while (result[i])
	{
		if (result[i] == (char)c)
		{
			return ((char *)&result[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *result, char *string_buffer)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	if (!(result))
	{
		result = (char *)malloc(1 * sizeof(char));
		result[0] = '\0';
	}
	if (!result || !string_buffer)
		return (NULL);
	new_s = (char *)malloc(((ft_strlen(result)) + (ft_strlen(string_buffer))
				+ 1) * (sizeof(char)));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	if (result)
		while (result[++i] != '\0')
			new_s[i] = result[i];
	while (string_buffer[j] != '\0')
		new_s[i++] = string_buffer[j++];
	new_s[ft_strlen(result) + ft_strlen(string_buffer)] = '\0';
	free(result);
	return (new_s);
}

size_t	ft_strlen(char *result)
{
	size_t	i;

	i = 0;
	if (!result)
		return (0);
	while (result[i] != '\0')
		i++;
	return (i);
}

t_map	*read_map_from_file(int fd, t_map *map)
{
	char	*line;
	int		x;

	x = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (line[0] != '\n')
		{
			mp_gr(map, x, line);
			x++;
		}
		else
		{
			free(line);
		}
		line = get_next_line(fd);
	}
	mp_gr_lst(map, x);
	return (map);
}
