/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:53:39 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 14:14:24 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chech_and_count_elements(t_game *game, char tmp_map)
{
	if (tmp_map == 'P')
		game->p_count++;
	else if (tmp_map == 'C')
		game->c_count++;
	else if (tmp_map == 'E')
		game->e_count++;
	else if (tmp_map != '0' && tmp_map != '1')
		game->i_count++;
}

void	count_map_elements(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		j;

	tmp_map = game->map->map;
	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			chech_and_count_elements(game, tmp_map[i][j]);
			j++;
		}
		i++;
	}
}

void	init_map_elements(t_game *game)
{
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->i_count = 0;
	game->mv_count = 0;
}

void	is_map_valid(t_game *game)
{
	if (game->c_count < 1)
		ft_error("Error\nInvalid collectible\n", game);
	if (game->e_count != 1)
		ft_error("Error\nInvalid exit\n", game);
	if (game->p_count != 1)
		ft_error("Error\nInvalid player\n", game);
	if (game->i_count > 0)
		ft_error("Error\nInvalid element\n", game);
}

void	ft_map_args_counter(t_game *game)
{
	init_map_elements(game);
	count_map_elements(game);
	is_map_valid(game);
}
