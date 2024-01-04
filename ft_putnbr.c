/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:42:00 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/03 16:27:12 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recurs(long n, int *index)
{
	(*index)++;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		recurs(n / 10, index);
		ft_putchar((n % 10) + '0');
	}
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long)n;
	if (nbr >= 0)
		recurs(nbr, &count);
	else
	{
		count++;
		ft_putchar('-');
		recurs(-nbr, &count);
	}
	return (count);
}
