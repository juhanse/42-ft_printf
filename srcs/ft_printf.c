/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:16:23 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 16:23:55 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft_parse(args[i]);
		i++;
	}
	va_end(args);
	return (1);
}
