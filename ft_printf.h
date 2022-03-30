/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:36:50 by jsubel            #+#    #+#             */
/*   Updated: 2022/01/05 14:27:08 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *format, va_list ap);
// -*-special character handling-*-
int	ft_printf_selector(const char *format, va_list ap);
int	ft_printf_char(int c);
int	ft_printf_nbr(int i);
int	ft_printf_percent(void);
int	ft_printf_string(char *str);
int	ft_printf_unsigned_int(unsigned int i);
int	ft_printf_pointer(unsigned long long ptr);
int	ft_printf_hex(unsigned int nbr, size_t mod);
#endif
