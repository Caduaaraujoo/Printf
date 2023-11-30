/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:12:19 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/30 14:01:28 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prefix_hex(unsigned long hex)
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
	temp = ft_convert_dec_hex(hex, 'x');
	str = ft_strjoin("0x", temp);
	free(temp);
	return (str);
}
