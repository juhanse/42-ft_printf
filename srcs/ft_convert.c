/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:24:10 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/02 11:50:15 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	else if (c == 'p')
		ft_print_address(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), 1, "0123456789", count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(args, int), 0, "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, int), 0, "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, int), 0, "0123456789ABCDEF", count);
	else if (c == '%')
		ft_putchar('%', count);
}
