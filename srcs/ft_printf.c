/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/01 23:16:59 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!s)
		return (0);
	i = -1;
	count = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_is_convertible(s[i + 1]))
			ft_convert(s[++i], args, &count);
		else if (s[i] == '%' && !ft_is_convertible(s[i + 1]))
			i++;
		else
			ft_putchar(s[i], &count);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("Hello %s | %d - %c | %%", "world!", 8, 'z');
	return (0);
}
