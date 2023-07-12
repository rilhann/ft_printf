/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:42:28 by ruilhan          #+#    #+#             */
/*   Updated: 2022/02/17 18:18:21 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_checker(va_list *args, char s);
int	ft_printf(const char *s, ...);

int	ft_putchar(char c);
int	ft_putnbr(int a, int *s);
int	ft_putstr(char *a);
int	ft_unsigned(unsigned int a, int *s);

int	ft_pointer(unsigned long long a, int *s);
int	ft_lowerx(unsigned int a, int *s);
int	ft_upperx(unsigned int a, int *s);

#endif