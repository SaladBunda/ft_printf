/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:51:30 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/03 22:39:58 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

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

int	ft_puthex(size_t x)
{
	char	*base;
	int		count;
	size_t	num;

	base = "0123456789abcdef";
	count = 0;
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

/* int main()
{
	ft_puthex(LONG_MAX);
	ft_putchar('\n');
	printf("%x",LONG_MAX);
} */