/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:18:29 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:41 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	ft_find_player(t_game *game)
{
	int		i;
	int		j;
	char	**tmp_map;

	tmp_map = game->map->map;
	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			j++;
		}
		i++;
	}
}

t_game	*ft_initialize(char *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("Error\nMemory allocation failed\n", NULL);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_error("Error\nMemory allocation failed\n", game);
	ft_map_height(map, game);
	ft_create_map(map, game);
	ft_map_checker(game);
	ft_map_args_counter(game);
	ft_find_player(game);
	return (game);
}
