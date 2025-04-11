/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:25:24 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:46 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static void	ft_allocate_map(t_game *game, int fd)
{
	game->map->map = malloc(sizeof(char *) * (game->map->height + 1));
	if (!game->map->map)
	{
		close(fd);
		ft_error("Malloc hatasi", game);
	}
}

void	ft_create_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("fd hatasi", game);
	ft_allocate_map(game, fd);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map->map[i] = NULL;
	close(fd);
}
