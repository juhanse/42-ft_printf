/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:10:30 by julienhanse       #+#    #+#             */
/*   Updated: 2024/11/06 12:48:44 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putchar_base(int nbr, char *base, int *count)
{
	write(1, &base[nbr], 1);
	*count += 1;
}

void	ft_putnbr_base(int nbr, int sign, char *base_set, int *count)
{
	unsigned int	tmp;
	unsigned int	size;

	tmp = nbr;
	size = ft_strlen(base_set);
	if (sign && nbr < 0)
	{
		tmp = -nbr;
		ft_putchar('-', count);
	}
	if (tmp > size - 1)
		ft_putnbr_base(tmp / size, sign, base_set, count);
	ft_putchar_base((tmp % size), base_set, count);
}
