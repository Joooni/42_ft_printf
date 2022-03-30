/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:26:48 by jsubel            #+#    #+#             */
/*   Updated: 2021/12/14 12:55:54 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_selector(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (format[1] == 'c')
		count = ft_printf_char(va_arg(ap, int));
	if (format[1] == 's')
		count = ft_printf_string(va_arg(ap, char *));
	if (format[1] == 'p')
		count = ft_printf_pointer(va_arg(ap, unsigned long long));
	if (format[1] == 'd')
		count = ft_printf_nbr(va_arg(ap, int));
	if (format[1] == 'i')
		count = ft_printf_nbr(va_arg(ap, int));
	if (format[1] == 'u')
		count = ft_printf_unsigned_int(va_arg(ap, unsigned int));
	if (format[1] == 'x')
		count = ft_printf_hex(va_arg(ap, unsigned int), 0);
	if (format[1] == 'X')
		count = ft_printf_hex(va_arg(ap, unsigned int), 1);
	if (format[1] == '%')
		count = ft_printf_percent();
	return (count);
}
