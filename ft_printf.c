/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/02 12:07:36 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

#include <stdio.h>
int	main(void)
{
	printf("Hello %s !\n", NULL);
	ft_printf("Hello %s !", NULL);
	return (0);
}
