/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:18:50 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/30 18:12:48 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *, ...)
{
	size_t	len;

	if (!s)
		return (0);
	va_list	args;
	va_start(args, s);
	len = ft_strlen(va_arg(args, char *));
	write(1, va_arg(args, char *), len);
	va_end(args);
	return (1);
}

int	main(void)
{
	printf("%d", ft_printf("Hello", "word"));
	return (0);
}
