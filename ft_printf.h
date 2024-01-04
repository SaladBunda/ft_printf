/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:37:50 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/03 22:39:46 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_put_uhex(size_t x);
int	ft_puthex(size_t x);
int	ft_printf(const char *s, ...);
int	ft_put_u(unsigned int n);

#endif