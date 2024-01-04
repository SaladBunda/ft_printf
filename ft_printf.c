/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:29 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/03 19:30:58 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

static void	printing(const char *s, va_list args, int *counter, int i)
{
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd' || s[i] == 'i')
				(*counter) += ft_putnbr(va_arg(args, int));
			else if (s[i] == 's')
				(*counter) += ft_putstr(va_arg(args, char *));
			else if (s[i] == 'c')
				(*counter) += ft_putchar(va_arg(args, int));
			else if (s[i] == 'X')
				(*counter) += ft_put_uhex(va_arg(args, unsigned int));
			else if (s[i] == 'x')
				(*counter) += ft_puthex(va_arg(args, unsigned int));
			else if (s[i] == 'p')
				(*counter) += ft_putstr("0x") + ft_puthex(va_arg(args, size_t));
			else if (s[i] == 'u')
				(*counter) += ft_put_u(va_arg(args, unsigned int));
			else if (s[i] == '%')
				(*counter) += ft_putchar('%');
			else if (s[i] == '\0')
				return ;
		}
		else
			(*counter) += ft_putchar(s[i]);
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

/* int main()
{
	return(ft_printf("%%%"));
} */