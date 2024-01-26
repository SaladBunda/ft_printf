/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:43:56 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/26 18:47:33 by ael-maaz         ###   ########.fr       */
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

int	ft_put_u(unsigned int n)
{
	int	i;

	i = 0;
	recurs(n, &i);
	return (i);
}

int	ft_put_s(int n)
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

int	printing_numbers(long n, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_put_s(n));
	else
		return (ft_put_u(n));
}
