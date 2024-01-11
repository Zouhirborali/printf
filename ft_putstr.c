/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:06:39 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/11 11:29:20 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*intt(char *s, char *format, int *re)
{
	int	l;

	l = 0;
	re[0] = git_n(format);
	re[1] = git_n_after_p(format);
	if ((int)ft_strlen(s) > re[1] && re[1] != 0 && check_poin(format))
		l = re[1];
	else if ((int)ft_strlen(s) <= re[1] || (re[1] == 0 && !check_poin(format)))
		l = ft_strlen(s);
	re[2] = l;
	re[3] = check_zero(format);
	re[4] = check_poin(format);
	return (re);
}

static void	pls1(char *s, int *re, int*j, int *x)
{
	while (re[0] > 0 && re[0] > re[2])
	{
		if (re[3])
			ft_putchar('0', j);
		else
			ft_putchar(' ', j);
		re[0]--;
	}
	while (s[*x] && (re[1] -1 >= *x || (!re[4] && re[1] == 0)))
		ft_putchar(s[(*x)++], j);
}

void	ft_putstr(char *s, char *format, int*j)
{
	int	x;
	int	*re;

	x = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", format, j);
		return ;
	}
	re = malloc(sizeof(re) * 6);
	re = intt(s, format, re);
	if (check_maiees(format))
	{
		while (s[x] && (re[1] -1 >= x || (!check_poin(format) && re[1] == 0)))
			ft_putchar(s[x++], j);
		while (re[0] > 0 && re[0] > re[2])
		{
			ft_putchar(' ', j);
			re[0]--;
		}
	}
	else
		pls1(s, re, j, &x);
	free(re);
}
