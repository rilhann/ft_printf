/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:43:22 by ruilhan          #+#    #+#             */
/*   Updated: 2022/02/22 20:06:05 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(va_list *args, char s)
{
	int	result;

	result = 0;
	if (s == 'c')
		result += ft_putchar(va_arg(*args, int));
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), &result);
	else if (s == 's')
		result += ft_putstr(va_arg(*args, char *));
	else if (s == '%')
		result += write(1, "%", 1);
	else if (s == 'p')
	{
		result += write(1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long), &result);
	}
	else if (s == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &result);
	else if (s == 'x')
		ft_lowerx(va_arg(*args, unsigned int), &result);
	else if (s == 'X')
		ft_upperx(va_arg(*args, unsigned int), &result);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, s);
	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_checker(&args, s[i]);
		}
		else
		{
			result += write(1, &s[i], 1);
		}
		i++;
	}
	return (result);
}
