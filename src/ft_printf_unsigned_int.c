/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:04:42 by jsubel            #+#    #+#             */
/*   Updated: 2021/12/14 11:58:26 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_uintlen(unsigned int i)
{
	int	counter;

	counter = 0;
	while (i > 0)
	{
		i = i / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_array(char *str, unsigned int nbr, size_t len)
{
	while (nbr > 0)
	{
		str[len - 1] = '0' + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

static char	*ft_uitoa(unsigned int i)
{
	int		len;
	char	*str;

	len = 0;
	len = ft_uintlen(i);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_array(str, i, len));
}

int	ft_printf_unsigned_int(unsigned int i)
{
	int		len;
	char	*str;

	len = 0;
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_uintlen(i);
	str = ft_uitoa(i);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
