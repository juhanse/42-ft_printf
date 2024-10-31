/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 16:37:15 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_parse(va_list c)
{
	if (c == 's')
	{
		ft_convert(c);
		return (1);
	}
	else if (c == 'c')
	{
		ft_convert(c);
		return (1);
	}
	else if (c == 'd')
	{
		ft_convert(c);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;

	if (!s)
		return (0);
	i = 0;
	va_start(args, s);
	while (args)
	{
		if (args[i] == '%' && args[i + 1])
			return (ft_parse(args[i]));
		i++;
	}
	va_end(args);
	return (0);
}
