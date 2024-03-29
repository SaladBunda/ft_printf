/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:37:50 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/26 18:39:17 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// int	ft_putnbr(unsigned int n, char c);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putx(size_t x, char c);
int	ft_printf(const char *s, ...);
// int	ft_put_u(unsigned int n);
int	printing_numbers(long n, char c);
#endif