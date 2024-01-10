/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_poin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:28 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 16:51:37 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_poin(char *format)
{
	int	x;

	x = 0;
	while (format[x])
	{
		while (format[x] && format[x] != '.')
			x++;
		while (format[x] && format[x] == '.')
			return (1);
		return (0);
	}
	return (0);
}
