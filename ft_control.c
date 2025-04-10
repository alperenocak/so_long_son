/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:16:26 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/10 15:38:20 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void	ft_av_control(char *av)
{
	int i;
	int fd;
	
	if (ft_strrchr(av, '/'))
		av = ft_strrchr(av, '/') + 1;
	i = ft_strlen(av);
	if (i < 5)
		ft_error("Error\nInvalid map name\n", NULL);
	else if (av[i - 4] != '.' || av[i - 3] != 'b' || av[i - 2] != 'e' || av[i - 1] != 'r')
		ft_error("Error\nInvalid map name\n", NULL);
	else
	{
		fd = open(av, O_RDONLY);
		if (fd == -1)
			ft_error("Error\nInvalid map\n", NULL);
		else
			close(fd);
	}
}
