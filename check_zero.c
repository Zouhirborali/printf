/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:53:49 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 16:54:41 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_zero(char *format)
{
	int	x;

	x = 0;
	while (format[x])
	{
		while (format[x] && !(format[x] >= '0' 
				&& format[x] <= '9') && format[x] != '.')
			x++;
		while (format[x] == '0')
			return (1);
		return (0);
	}
	return (0);
}
