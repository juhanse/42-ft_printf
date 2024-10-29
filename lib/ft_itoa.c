/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:26:35 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/29 17:27:07 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_count_digit(int n)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = n;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		digits;
	char		*buffer;

	num = n;
	digits = ft_count_digit(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	buffer = (char *)malloc((digits + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[digits] = '\0';
	while (digits--)
	{
		buffer[digits] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}
