/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:39 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 17:09:31 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, char *format, int*j)
{
	int	x;
	int	l;
	int	len;
	int	lens;

	x = 0;
	l = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", format, j);
		return ;
	}
	len = git_n(format);
	lens = git_n_after_p(format);
	if((int)ft_strlen(s)> lens && lens !=0 && check_poin(format))
		l = lens;
	else if((int)ft_strlen(s) <= lens || (lens ==0 && !check_poin(format)))
		l = ft_strlen(s);
	if(check_maiees(format))
	{
		while(s[x]&& (lens -1 >= x || (!check_poin(format) && lens ==0)))
			ft_putchar(s[x++],j);
		while(len>0 && len > l)
		{
			ft_putchar(' ',j);
			len--;
		}
	}
	else
	{
		
		while(len>0 && len > l)
		{
			if(check_zero(format))
				ft_putchar('0',j);
			else
				ft_putchar(' ',j);
			len--;
		}
		while(s[x]&& (lens -1 >= x || (!check_poin(format) && lens ==0)))
			ft_putchar(s[x++],j);
	}


}



