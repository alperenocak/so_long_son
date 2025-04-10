/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:07:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/10 18:00:20 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "ft_printf/ft_printf.h"

int keyboard(int keycode, t_game *game)
{
    if (keycode == ESC)
        mlx_exit("Exit", game);
    else if (keycode == W && game->map->map[game->player_y - 1][game->player_x] != '1')
        game->player_y--;
    else if (keycode == A && game->map->map[game->player_y][game->player_x - 1] != '1')
        game->player_x--;
    else if (keycode == D && game->map->map[game->player_y][game->player_x + 1] != '1')
        game->player_x++;
    else if (keycode == S && game->map->map[game->player_y + 1][game->player_x] != '1')
        game->player_y++;
    else
        return(0);
    ft_printf("Moves: %d\n", ++game->mv_count);
    if (game->map->map[game->player_y][game->player_x] == 'C')
    {
        game->c_count--;
        game->map->map[game->player_y][game->player_x] = '0';
    }
    if (game->map->map[game->player_y][game->player_x] == 'E' && game->c_count == 0)
        mlx_exit("Win", game);
    return(0);
}

void    init_mlx(t_game *game)
{
    int x;
    int y;

    game->mlx = mlx_init();
    if (!game->mlx)
        mlx_exit("Error\nMlx not initialize\n", game);
    game->win= mlx_new_window(game->mlx, game->map->height * PIXEL, game->map->width * PIXEL, "so_long");
    game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &y, &x);
    game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &y, &x);
    game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &y, &x);
    game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &y, &x);
    game->background = mlx_xpm_file_to_image(game->mlx, "textures/bground.xpm", &y, &x);
    if (!game->win || !game->player || !game->coin || !game->exit
		|| !game->wall || !game->background)
		mlx_exit("Error\nTextures not loaded!", game);
}