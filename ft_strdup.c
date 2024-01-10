/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:49:10 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 17:13:31 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1, char *re)
{
	int	x;

	x = 0;
	re = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[x] = s1[x];
		x++;
	}
	re[x] = '\0';
	return (re);
}