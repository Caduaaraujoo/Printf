/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:29 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/29 19:34:38 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

static char	*ft_convert_hex_dec(unsigned long hex)
{
	char	*str;
	char	*temp;

	if (hex == 0)
	{
		ft_putstr_fd("(nil)", 1);
		str = ft_strdup("(nil)");
		return (str);
	}
	ft_putstr_fd("0x", 1);
	temp =  ft_convert_dec_hex(hex, 'x');
	str = ft_strjoin("0x", temp);
	free(temp);
	return (str);
}

static union u_return_value	ft_configure_va_arg(char c, va_list args)
{
	union u_return_value	var_type;

	if (c == 's')
	{
		var_type.va_type_str = va_arg(args, char *);
		if (var_type.va_type_str == NULL)
			var_type.va_type_str = "(null)";
	}
	else if( c == 'p')
		var_type.va_type_pointer = va_arg(args, unsigned long);
	else if (c == 'u' || c == 'x' || c == 'X')
		var_type.va_type_unsigned_int = va_arg(args, unsigned int);
	else
		var_type.va_type_int = va_arg(args, int);
	return (var_type);
}

static union u_return_value	ft_verify_type_print(char c, va_list args)
{
	union u_return_value	result;

	if (c != '%')
		result = ft_configure_va_arg(c, args);
	if (c == 'c')
		ft_putchar_fd(result.va_type_int, 1);
	else if (c == 's')
		ft_putstr_fd((char *)result.va_type_str, 1);
	else if (c == 'p')
		result.va_type_str = ft_convert_hex_dec(result.va_type_pointer);
	else if (c == 'd')
		ft_putnbr_fd(result.va_type_int, 1);
	else if (c == 'i')
		ft_putnbr_fd(result.va_type_int, 1);
	else if (c == 'u')
		ft_putnbr_unsigned(result.va_type_unsigned_int, 1);
	else if (c == 'x')
		result.va_type_str = ft_convert_dec_hex(result.va_type_unsigned_int, 'x');
	else if (c == 'X')
		result.va_type_str = ft_convert_dec_hex(result.va_type_unsigned_int, 'X');
	else if (c == '%')
		ft_putchar_fd('%', 1);

	return(result);
}

static int ft_length_printf(char type, union u_return_value value_return)
{
	int	len;
	char 	*str;

	len = 0;
	if (type == 'c' || type == '%')
		return (1);
	if (type == 'x' || type == 'X' || type == 'p')
	{
		len = ft_strlen(value_return.va_type_str);
		free(value_return.va_type_str);
		return (len);
	}
	if (type != 's')
	{
		if (type == 'u')
			str = ft_itoa_unsigned(value_return.va_type_unsigned_int);
		else
			str = ft_itoa(value_return.va_type_int);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (ft_strlen(value_return.va_type_str));
}

int	ft_printf(const char *value, ...)
{
	int		i;
	int		amount;
	va_list	args;
	union u_return_value	result_return;

	va_start(args, value);
	i = 0;
	amount = 0;
	while (value[i])
	{
		if (value[i] == '%')
		{
				result_return = ft_verify_type_print(value[i + 1], args);
				amount += ft_length_printf(value[i + 1], result_return);
				i += 2;
				if (!value[i])
					break ;
				continue ;
		}
		ft_putchar_fd(value[i], 1);
		amount++;
		i++;
	}
	va_end(args);
	return (amount);
}

// int	main(void)
// {
// 	int r_original;
// 	int r_myprint;
// 	int address;

// 	r_original = 0;
// 	r_myprint = 0;

// 	r_myprint = ft_printf("%p", 0);
// 	printf("\n");
// 	r_original = printf("%p", 0);
// 	printf("\n");

// 	printf("RETORNO ORIGINAL : %d\n", r_original);
// 	printf("RETORNO MINHA PRINTF : %d\n", r_myprint);
// 	return (0);
// }
