/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:49:10 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/10 16:28:09 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

static void ft_check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->width)
	{
		if ((game->map->map[0][i] != '1') || (game->map->map[game->map->height - 1][i] != '1'))
			ft_error("Error\nMap is not surrounded by walls\n", game);
		i++;
	}
	i = 0;
	while (i < game->map->height)
	{
		if ((game->map->map[i][0] != '1') || (game->map->map[i][game->map->width - 1] != '1'))
			ft_error("Error\nMap is not surrounded by walls\n", game);
		i++;
	}
}

static void	ft_check_rectengular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->map->height)
	{
		len = ft_strlen(game->map->map[i]);
		if (len != game->map->width)
			ft_error("Error\nMap is not rectangular\n", game);
		i++;
	}
}

void	ft_map_checker(t_game *game)
{
	ft_check_rectengular(game);
	ft_check_walls(game);
}

static void	ft_assigm(int height, int width, t_game *game)
{
	if (height <= 0 || width <= 0)
		ft_error("Error\nInvalid map!\n", game);
	game->map->width = width;
	game->map->height = height;
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
	if (line)
	{
		width = ft_strlen(line);
		if (line[width - 1] == '\n')
			width--;
		height++;
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	ft_assigm(height, width, game);
}
