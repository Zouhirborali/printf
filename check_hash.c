/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:05:42 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 20:06:06 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_hash(char *format)
{
	int	x;

	x = 0;
	while (format[x])
	{
		while ((format[x] && (!(format[x] >= '0' && 
						format[x] <= '9') && format[x] != '.' && 
					format[x] != '#')) || format[x] == '0')
			x++;
		if (format[x] && format[x] == '#')
			return (1);
		return (0);
	}
	return (0);
}
