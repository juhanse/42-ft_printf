/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:10:30 by julienhanse       #+#    #+#             */
/*   Updated: 2024/10/31 23:13:08 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putchar_base(int n, char *base, int *count)
{
	write(1, &base[n], 1);
	*count += 1;
}

void	ft_putnbr_base(int n, int sign, char *base_set, int *count)
{
	unsigned int	un;
	unsigned int	len;

	un = n;
	len = ft_strlen(base_set);
	if (n < 0 && sign)
	{
		un = -n;
		ft_putchar('-', count);
	}
	if (un > len - 1)
		ft_putnbr_base(un / len, sign, base_set, count);
	ft_putchar_base((un % len), base_set, count);
}
