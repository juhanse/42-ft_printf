/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 23:22:16 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		res;
	size_t	i;
	va_list	args;

	if (!s)
		return (0);
	i = -1;
	res = 0;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_is_convertible(s[i + 1]))
			ft_convert(s[++i], args, &res);
		else if (s[i] == '%' && !ft_is_convertible(s[i + 1]))
			i++;
		else
			write(1, &s[i], 1);
	}
	va_end(args);
	return (res);
}

int	main(void)
{
	printf("Hello %s | %d - %c | %%", "world!", 20, 'z');
	return (0);
}
