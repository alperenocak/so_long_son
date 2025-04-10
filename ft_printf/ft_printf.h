/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:41:39 by yuocak            #+#    #+#             */
/*   Updated: 2024/11/27 15:28:39 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putint(int n);
int	ft_putuint(unsigned int n);
int	ft_putpoint(unsigned long n);
int	ft_hex(unsigned long n, char c);
int	ft_printf(const char *format, ...);
#endif
