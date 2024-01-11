/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:07:54 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/11 11:08:38 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*intt(char *s, char *format, int *re)
{
	int	if_m;

	re[0] = git_n(format);
	re[1] = git_n_after_p(format);
	re[2] = git_n_after_p(format);
	if_m = 0 ;
	if (s[0] == '-')
		if_m = ft_strlen(s) - 1;
	else
		if_m = ft_strlen(s);
	if (s[0] == '0' && check_poin(format) && re[2] == 0)
		if_m = 0;
	re[3] = if_m;
	re[4] = check_sp(format);
	re[5] = check_pluse(format);
	re[6] = check_poin(format);
	re[7] = check_sp(format);
	re[8] = check_zero(format);
	re[9] = git_n(format);
	return (re);
}

static void	min1(char *s, int*j, int *re, int x)
{
	if (re[4] &&!re[5] && s[0] != '-')
	{
		ft_putchar(' ', j);
		re[0]--;
	}
	else if (re[5] || s[0] == '-')
	{
		if (s[0] != '-')
			ft_putchar('+', j);
		else
			ft_putchar('-', j);
		re[0]--;
	}
	while (re[2] - re[3] > 0 && re[2]-- > re[3])
		ft_putchar('0', j);
	while (s[x])
	{
		if (s[x] == '-' || s[x] == '+')
			x++;
		else if (ft_strlen(s) == 1 && s[x] == '0' && re[6] && re[2] == 0)
			x++;
		else
			ft_putchar(s[x++], j);
	}
}

static void	pl1(char *s, int*j, int *re)
{
	if (re[7] || re[5] || s[0] == '-')
	{
		if (!re[5] && s[0] != '-')
			ft_putchar(' ', j);
		re[0]--;
	}
	if ((re[5] || s[0] == '-') && re[8] && re[1] == 0 && !re[6])
	{
		if (s[0] != '-')
			ft_putchar('+', j);
		else
			ft_putchar('-', j);
	}
	while ((re[0] - re[1] > 0 && re[0] > 0 && re[9] > re[3]
			&& re[2] >= re[3]) 
		|| (re[2] < re[3] && re[0] - re[3] > 0 && re[0] > 0 && re[9] > re[3]))
	{
		if (re[8] && re[1] == 0 && !re[6])
			ft_putchar('0', j);
		else
			ft_putchar(' ', j);
		re[0]--;
	}
	re[0] = re[9];
}

static void	pl2(char *s, int*j, int *re, int *x)
{
	if (((re[5] || s[0] == '-') && (!re[8] || re[6])) 
		|| (s[0] == '-' && !re[5] && !re[8]))
	{
		if (s[0] != '-')
			ft_putchar('+', j);
		else
			ft_putchar('-', j);
	}
	while (re[2] - re[3] > 0 && re[2] > re[3])
	{
		ft_putchar('0', j);
		re[2]--;
	}
	while (s[*x])
	{
		if (s[*x] == '-' || s[*x] == '+')
			(*x)++;
		else if (ft_strlen(s) == 1 && s[*x] == '0' && re[6] && re[1] == 0)
			(*x)++;
		else
			ft_putchar(s[(*x)++], j);
	}
}

void	ft_putnbr(char *s, char *format, int*j)
{
	int	x;
	int	*re;

	x = 0;
	re = malloc(sizeof(re) * 10);
	re = intt(s, format, re);
	if (check_maiees(format))
	{
		min1(s, j, re, x);
		while ((re[0] - re[1] > 0 && re[0] > 0 && git_n(format) > re[3] 
				&& re[1] >= re[3])
			|| (re[1] < re[3] && re[0] - re[3] > 0 && re[0] > 0 
				&& git_n(format) > re[3]))
		{
			ft_putchar(' ', j);
			re[0]--;
		}
	}
	else
	{
		pl1(s, j, re);
		pl2(s, j, re, &x);
	}
	free(re);
}
