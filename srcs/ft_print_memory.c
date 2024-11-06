/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:13:49 by juhanse           #+#    #+#             */
/*   Updated: 2024/11/06 12:07:09 by juhanse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putchar_mem(int nbr, char *base, int *count)
{
	write(1, &base[nbr], 1);
	*count += 1;
}

static void	ft_putmem(unsigned long nbr, int *count)
{
	if (nbr > 15)
		ft_putmem(nbr / 16, count);
	ft_putchar_mem((nbr % 16), "0123456789abcdef", count);
}

void	ft_print_address(void *add, int *count)
{
	unsigned long	hex;

	hex = (unsigned long)add;
	ft_putstr("0x", count);
	ft_putmem(hex, count);
}
