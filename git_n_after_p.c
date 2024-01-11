/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_n_after_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:30:42 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/11 11:28:35 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	git_n_after_p(char *format)
{
	int	x;
	int	re;

	x = 0;
	re = 0;
	while (format[x])
	{
		while (format[x] && format[x] != '.')
			x++;
		while (format[x] && format[x] == '.')
			x++;
		while (format[x] && (format[x] >= '0' && format[x] <= '9'))
			re = (re * 10) + (format[x++] - '0');
		return (re);
	}
	return (re);
}
