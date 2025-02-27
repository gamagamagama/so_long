/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 03:46:18 by matus             #+#    #+#             */
/*   Updated: 2025/02/27 05:48:19 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_number(int number)
{
	if (number > 9)
		ft_put_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

int	bad_len(int first_len, char *line, int fd)
{
	int	i;

	i = ft_strlen(line);
	if (i != first_len)
	{
		get_next_line(-1, 1);
		fc(line, fd);
		return (0);
	}
	free(line);
	return (1);
}

void	fc(char *line, int fd)
{
	free(line);
	close(fd);
}

int	count_lines(const char *path)
{
	int		fd;
	int		lines;
	int		first_len;
	char	*line;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	first_len = line_check(fd);
	if (first_len == -1)
		return (-1);
	lines = 0;
	while ((1))
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
			lines++;
		if (!bad_len(first_len, line, fd))
			return (-1);
	}
	fc(line, fd);
	return (lines);
}

bool	exit_recast(mlx_image_t *exit_out, t_wl_pl_bb *bb, int i)
{
	return ((bb->pr - bb->of > (exit_out->instances[i].x - (int)exit_out->width
				/ 2) && (bb->pl + bb->of < exit_out->instances[i].x
				+ (int)exit_out->width / 2) && (bb->pb
				- bb->of > exit_out->instances[i].y - (int)exit_out->height / 2)
			&& (bb->pt + bb->of < exit_out->instances[i].y
				+ (int)exit_out->height / 2)));
}
