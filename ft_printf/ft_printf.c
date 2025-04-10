/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:15:18 by yuocak            #+#    #+#             */
/*   Updated: 2024/11/26 15:54:04 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_handle(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_putpoint(va_arg(args, unsigned long)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

static int	ft_format(va_list args, const char *format)
{
	int	len;
	int	tmp;
	int	i;

	len = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			tmp = ft_handle(args, format[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	len = ft_format(args, format);
	va_end(args);
	return (len);
}
