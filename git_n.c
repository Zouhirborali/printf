/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:31:30 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 17:33:16 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	git_n(char *format)
{
	int	x;
	int	re;

	x = 0;
	re = 0;
	while (format[x])
	{
		while ((format[x] &&!(format[x] >= '0' && format[x] <= '9')
				&& format[x] != '.') || format[x] == '0')
			x++;
		while (format[x] && (format[x] >= '0' && format[x] <= '9'))
			re = (re * 10) + (format[x++] - '0');
		return (re);
	}
	return (re);
}