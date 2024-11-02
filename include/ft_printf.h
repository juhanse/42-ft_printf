/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:19:15 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/02 11:45:02 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr_base(int n, int sign, char *base_set, int *count);

int		ft_is_convertible(char c);
void	ft_convert(char c, va_list args, int *count);
void	ft_print_address(void *add, int *count);

int		ft_printf(const char *s, ...);

#endif
