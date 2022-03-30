/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:35:50 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/30 10:47:39 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	count = ft_vprintf(format, ap);
	va_end(ap);
	return (count);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_printf_selector(&format[i], ap);
			i++;
		}
		else
			count += ft_printf_char(format[i]);
		i++;
	}
	return (count);
}
