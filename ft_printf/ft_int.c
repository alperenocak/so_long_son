/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:43:01 by yuocak            #+#    #+#             */
/*   Updated: 2024/11/26 18:20:56 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putint(int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n > 9)
	{
		tmp = ft_putint(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(n % 10 + '0');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	ft_putuint(unsigned int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n > 9)
	{
		tmp = ft_putuint(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(n % 10 + '0');
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
