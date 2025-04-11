/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:53:34 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:07 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == 'C')
		game->temp_c--;
	else if (map[y][x] == 'E')
		game->temp_e--;
	if (map[y][x] == '1' || map[y][x] == 'A')
		return ;
	map[y][x] = 'A';
	ft_flood_fill(map, x + 1, y, game);
	ft_flood_fill(map, x - 1, y, game);
	ft_flood_fill(map, x, y + 1, game);
	ft_flood_fill(map, x, y - 1, game);
}

char	**copy_map_allocation(t_game *game)
{
	char	**copy;
	int		i;

	copy = ft_calloc(sizeof(char *), game->map->height + 1);
	if (!copy)
		ft_error("Error\nAlloceted Error!", game);
	i = 0;
	while (i < game->map->height)
	{
		copy[i] = ft_strdup(game->map->map[i]);
		if (!copy)
		{
			ft_free_map(copy);
			ft_error("Error\nAlloceted error\n", game);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_map_reachable(t_game *game)
{
	char	**tmp_map;

	game->temp_c = game->c_count;
	game->temp_e = 1;
	tmp_map = copy_map_allocation(game);
	ft_flood_fill(tmp_map, game->player_x, game->player_y, game);
	if (game->temp_c > 0 || game->temp_e > 0)
	{
		ft_free_map(tmp_map);
		ft_error("Error\nMap is not accessible\n", game);
	}
	ft_free_map(tmp_map);
}
