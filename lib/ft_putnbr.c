/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienhanse <julienhanse@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:25:40 by juhanse           #+#    #+#             */
/*   Updated: 2024/10/31 23:04:05 by julienhanse      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}
