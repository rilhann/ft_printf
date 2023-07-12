/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruilhan <ruilhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:43:25 by ruilhan          #+#    #+#             */
/*   Updated: 2022/02/17 18:48:41 by ruilhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int a, int *s)
{
	if (a == -2147483648)
	{
		*s += ft_putchar('-');
		*s += ft_putchar('2');
		a = 147483648;
	}
	if (a < 0)
	{
		*s += ft_putchar('-');
		a *= -1;
	}
	if (a >= 0 && a <= 9)
	{
		*s += ft_putchar(a + 48);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10, s);
		ft_putnbr(a % 10, s);
	}
	return (*s);
}

int	ft_putstr(char *a)
{
	int	i;

	i = 0;
	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int a, int *s)
{
	if (a < 0)
	{
		*s += ft_putchar('-');
		a *= -1;
	}
	if (a >= 0 && a <= 9)
	{
		*s += ft_putchar(a + 48);
	}
	if (a > 9)
	{
		ft_unsigned(a / 10, s);
		ft_unsigned(a % 10, s);
	}
	return (*s);
}
