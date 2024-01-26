/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:29 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/26 18:47:20 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printing(const char *s, va_list args, int *ct, int i)
{
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
				(*ct) += printing_numbers(va_arg(args, long), s[i]);
			else if (s[i] == 's')
				(*ct) += ft_putstr(va_arg(args, char *));
			else if (s[i] == 'c')
				(*ct) += ft_putchar(va_arg(args, int));
			else if (s[i] == 'x' || s[i] == 'X')
				(*ct) += ft_putx(va_arg(args, unsigned int), s[i]);
			else if (s[i] == 'p')
				(*ct) += ft_putstr("0x") + ft_putx(va_arg(args, size_t), 'p');
			else if (s[i] == '%')
				(*ct) += ft_putchar('%');
			else if (s[i] == '\0')
				return ;
			else
				(*ct) += ft_putchar(s[i]);
		}
		else
			(*ct) += ft_putchar(s[i]);
	}
}

int	ft_printf(const char *s, ...)
{
	int		counter;
	int		i;
	va_list	args;

	i = -1;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, s);
	counter = 0;
	printing(s, args, &counter, i);
	va_end(args);
	return (counter);
}
