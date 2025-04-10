/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:10:22 by yuocak            #+#    #+#             */
/*   Updated: 2024/11/26 20:46:20 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_hex(unsigned long n, char c)
{
	int	len;
	int	tmp;

	len = 0;
	if (n > 15)
	{
		tmp = ft_hex(n / 16, c);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
			return (-1);
	}
	if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[n % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_putpoint(unsigned long n)
{
	int	len;
	int	tmp;

	if (n == 0)
		return (write(1, "(nil)", 5));
	len = 0;
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	len += tmp;
	tmp = ft_hex(n, 'x');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
