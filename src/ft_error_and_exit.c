/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:17:33 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:30 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"
#include "../ft_printf/ft_printf.h"

int	mlx_exit(char *str, t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_error(str, game);
	return (1);
}

int	close_window(t_game *game)
{
	mlx_exit("Exit", game);
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(char *av, t_game *game)
{
	if (game)
	{
		ft_free_map(game->map->map);
		free(game->map);
		free(game);
	}
	ft_printf("%s\n", av);
	exit(1);
}
