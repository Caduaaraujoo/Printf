/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:15:02 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/29 19:36:48 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

union				u_return_value
{
	unsigned int	va_type_unsigned_int;
	unsigned long	va_type_pointer;
	int				va_type_int;
	char			*va_type_str;
};
char				*ft_convert_dec_hex(unsigned long n, char x);
char				*ft_itoa_unsigned(unsigned int n);
void				ft_putnbr_unsigned(unsigned int number, int fd);
int					ft_printf(const char *, ...);

#endif