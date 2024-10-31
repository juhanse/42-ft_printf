/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:24:10 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 21:59:35 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_is_convertible(char c)
{
	size_t	i;
	char	*convertible;

	i = -1;
	convertible = "cspdiuxX%";
	while (convertible[++i])
		if (c == convertible[i])
			return (1);
	return (0);
}

void	ft_convert(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, void *), count);
	else if (c == '%')
		ft_putchar('%', count);
}
