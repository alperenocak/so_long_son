/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:54 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 00:02:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 48

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*background;
	t_map	*map;
	int     temp_c;
    int     temp_e;
	int		p_count;
	int		e_count;
	int		c_count;
	int		i_count;
	int		player_x;
	int		player_y;
	int		mv_count;
}	t_game;

void	ft_error(char *av, t_game *game);
void    ft_free_map(char **map);
void	ft_av_control(char *av);
t_game	*ft_initialize(char *map);
void	ft_map_height(char *filename, t_game *game);
void	ft_create_map(char *filename, t_game *game);
char	*get_next_line(int fd);
void    ft_map_args_counter(t_game *game);
void	ft_map_checker(t_game *game);
void    ft_map_reachable(t_game *game);
void    init_mlx(t_game *game);
int 	keyboard(int keycode, t_game *game);
int		close_window(t_game *game);
int 	mlx_exit(char *str, t_game *game);
int 	render(t_game *game);
int 	put_mlx(t_game *game);
#endif