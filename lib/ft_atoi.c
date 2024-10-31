/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:26:20 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 21:49:43 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_overflow(long sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int		i;
	long	sign;
	long	tmp;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp = result;
		result = (result * 10) + (s[i] - 48);
		if (tmp > result)
			return (ft_overflow(sign));
		i++;
	}
	return ((int) result * sign);
}
