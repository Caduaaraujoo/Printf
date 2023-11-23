/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:29 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/23 20:51:49 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

union u_return_value	ft_configure_va_arg(char c, va_list args)
{
	union u_return_value	var_type;

	if (c == 's')
		var_type.va_type_str = va_arg(args, char *);
	else
		var_type.va_type_int = va_arg(args, int);
	return (var_type);
}

void	ft_verify_type_print(char c, va_list args)
{
	union u_return_value	result;

	result = ft_configure_va_arg(c, args);
	if (c == 'c')
		ft_putchar_fd(result.va_type_int, 1);
	else if (c == 's')
		ft_putstr_fd((char *)result.va_type_str, 1);
	else if (c == 'p')
		printf("a");
	else if (c == 'd')
		ft_putnbr_fd(result.va_type_int, 1);
	else if (c == 'i')
		printf("a");
	else if (c == 'u')
		printf("a");
	else if (c == 'x')
		printf("a");
	else if (c == 'X')
		printf("a");
	else if (c == '%')
		printf("a");
}

int	ft_printf(const char *value, ...)
{
	int		i;
	int		amount;
	va_list	args;

	va_start(args, value);
	i = 0;
	amount = 0;
	while (value[i])
	{
		if (value[i] == '%')
		{
			ft_verify_type_print(value[i + 1], args);
			i += 2;
			amount++;
		}
		if (!value[i])
			break ;
		ft_putchar_fd(value[i], 1);
		amount++;
		i++;
	}
	va_end(args);
	return (amount);
}

int	main(void)
{
	int	r_original;
	int	r_myprint;

	r_original = 0;
	r_myprint = 0;
	r_myprint = ft_printf(" %c ", '0');
	printf("\n");
	r_original = printf(" %c ", '0');
	printf("\n");
	r_myprint = ft_printf(" %c", '0' - 256);
	printf("\n");
	r_original = printf(" %c", '0' - 256);
	printf("\n");
	r_myprint = ft_printf(" %c ", '0' + 256);
	printf("\n");
	r_original = printf(" %c ", '0' + 256);
	printf("\n");
	r_myprint = ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	r_original = printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	r_myprint = ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	r_original = printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	r_myprint = ft_printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	r_original = printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	r_myprint = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	r_original = printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	r_myprint = ft_printf(" %c %c %c ", 0, '1', '2');
	printf("\n");
	r_original = printf(" %c %c %c ", 0, '1', '2');
	printf("\n");

	printf("RETORNO ORIGINAL : %d\n", r_original);
	printf("RETORNO MINHA PRINTF : %d\n", r_myprint);
	return (0);
}
