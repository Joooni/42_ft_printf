/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:56:53 by jsubel            #+#    #+#             */
/*   Updated: 2021/12/14 12:59:17 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_printf_puthex(unsigned int nbr, size_t mod)
{
	if (nbr >= 16)
	{
		ft_printf_puthex(nbr / 16, mod);
		ft_printf_puthex(nbr % 16, mod);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd('0' + nbr, 1);
		else if (mod == 1)
			ft_putchar_fd('A' + (nbr - 10), 1);
		else if (mod == 0)
			ft_putchar_fd('a' + (nbr - 10), 1);
	}
}

static int	ft_printf_lenhex(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

int	ft_printf_hex(unsigned int nbr, size_t mod)
{
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_printf_puthex(nbr, mod);
	return (ft_printf_lenhex(nbr));
}
