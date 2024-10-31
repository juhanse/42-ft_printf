/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:15 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 23:18:50 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define CONVERTIBLE "cspdiuxX%"
# define DECIMAL "0123456789"
# define UP_HEXADECIMAL "0123456789ABCDEF"
# define LOW_HEXADECIMAL "0123456789abcdef"
# define SIGNED 1
# define UNSIGNED 0

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_base(int n, int sign, char *base_set, int *count);

int		ft_is_convertible(char c);
void	ft_convert(char c, va_list args, int *count);
void	ft_print_address(void *add, int *count);

int		ft_printf(const char *s, ...);

#endif
