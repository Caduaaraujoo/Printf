/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:29 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/20 16:47:46 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *value, ...)
{
	va_list	args;
	char	c;
	int		i;

	va_start(args, value);
	i = 0;
	while (value[i] && value[i] != '%')
		i++;
	if (value[i + 1] == 'c')
	{
		c = va_arg(args, int);
		ft_putchar(c);
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	ft_printf("    %c", 'c');
	return (0);
}
