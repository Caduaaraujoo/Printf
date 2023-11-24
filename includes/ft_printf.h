/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:15:02 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/24 19:12:49 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

union						u_return_value
{
	unsigned int			va_type_unsigned_int;
	int						va_type_int;
	char					*va_type_str;
};

void						ft_putnbr_unsigned(unsigned int number);
int							ft_printf(const char *, ...);
union u_return_value	ft_verify_type_print(char c, va_list args);
union u_return_value	ft_configure_va_arg(char c, va_list args);
int	ft_length_printf(char type, union u_return_value value_return);

#endif