/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:15:37 by oshcheho          #+#    #+#             */
/*   Updated: 2024/05/24 10:30:54 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(unsigned long nbr, char format)
{
	char	*base;
	int		res;
	char	buffer[32];
	int		i;

	i = 0;
	res = 0;
	base = "0123456789abcdef";
	if (format == 'p')
		res += ft_putstr_fd("0x", 1);
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
		return (res + ft_putchar_fd('0', 1));
	while (nbr > 0)
	{
		buffer[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	while (i > 0)
		res += ft_putchar_fd(buffer[--i], 1);
	return (res);
}
//