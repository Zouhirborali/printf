/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:13:57 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 17:30:37 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(const char *s, unsigned int start, size_t len, char	*buffer)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);

	while (s[start] && i < len)
		buffer[i++] = s[start++];

	buffer[i] = '\0';
	return (buffer);
}
