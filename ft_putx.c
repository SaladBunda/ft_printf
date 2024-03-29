/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:51:30 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/25 16:26:39 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recurs(size_t n, char *base)
{
	if (n < 16)
		ft_putchar(base[n]);
	else
	{
		recurs(n / 16, base);
		ft_putchar(base[n % 16]);
	}
}

int	ft_putx(size_t x, char c)
{
	char	*base;
	int		count;
	size_t	num;

	count = 0;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	num = x;
	if (num == 0)
		count = 1;
	else
	{
		while (num > 0)
		{
			num /= 16;
			count++;
		}
	}
	recurs(x, base);
	return (count);
}
