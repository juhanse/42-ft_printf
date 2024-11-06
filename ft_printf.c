/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/06 12:49:49 by juhanse          ###   ########.fr       */
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
	void	*p;

	printf("%d\n", printf("%c | %s | %p | %d | %i | %u | %x | %X | %%\n", 'a', "test", &p, -42, 0X42, 42, 42, 42));
	ft_printf("%d\n", ft_printf("%c | %s | %p | %d | %i | %u | %x | %X | %%\n", 'a', "test", &p, -42, 0X42, 42, 42, 42));
	return (0);
}
