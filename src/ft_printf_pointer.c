/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:01:39 by jsubel            #+#    #+#             */
/*   Updated: 2021/12/14 13:00:48 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_lenptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

static void	ft_printf_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_printf_putptr(ptr / 16);
		ft_printf_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd('0' + ptr, 1);
		else
			ft_putchar_fd('a' + (ptr - 10), 1);
	}
}

int	ft_printf_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "0x0", 3);
	else
	{
		len += write(1, "0x", 2);
		ft_printf_putptr(ptr);
		len += ft_printf_lenptr(ptr);
	}
	return (len);
}
