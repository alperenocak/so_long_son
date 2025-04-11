/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:16:26 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/11 16:59:14 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	ft_av_control(char *av)
{
	int	i;
	int	fd;

	i = ft_strlen(av);
	if (i < 5 || av[i - 5] == '/')
		ft_error("Error\nInvalid map name\n", NULL);
	else if (ft_strncmp(av + i - 4, ".ber", 4))
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
