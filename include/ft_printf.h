/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:15 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 22:02:47 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // REMOVE
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);

int		ft_printf(const char *s, ...);
int		ft_is_convertible(char c);
void	ft_convert(char c, va_list args, int *count);

#endif
