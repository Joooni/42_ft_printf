/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:42:43 by jsubel            #+#    #+#             */
/*   Updated: 2021/12/14 12:58:47 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_nbr(int i)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(i);
	len = ft_strlen(nbr);
	ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}
