/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:41:49 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:51 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	ft_assigm(int height, int width, t_game *game)
{
	if (height <= 0 || width <= 0)
		ft_error("Error\nInvalid map!\n", game);
	game->map->width = width;
	game->map->height = height;
}

static void	ft_map_height_cont(int *width, int *height, char *line)
{
	if (line)
	{
		*(width) = ft_strlen(line);
		if (line[*(width) - 1] == '\n')
			*(width) -= 1;
		*(height) += 1;
		free(line);
	}
}

void	ft_map_height(char *filename, t_game *game)
{
	int		fd;
	int		height;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFd Error\n", game);
	height = 0;
	line = get_next_line(fd);
	ft_map_height_cont(&width, &height, line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_assigm(height, width, game);
}
