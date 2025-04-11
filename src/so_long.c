/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:25:58 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:53 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		ft_av_control(av[1]);
		game = ft_initialize(av[1]);
		ft_map_reachable(game);
		init_mlx(game);
		mlx_hook(game->win, 2, 1L << 0, keyboard, game);
		mlx_hook(game->win, 17, 0, close_window, game);
		mlx_loop_hook(game->mlx, put_mlx, game);
		mlx_loop(game->mlx);
	}
	else
		ft_error("Error\nInvalid number of arguments\n", NULL);
	return (0);
}
