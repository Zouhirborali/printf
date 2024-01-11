/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:21:33 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 21:06:12 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_uu(unsigned int n, int *j)
{
	if (n < 10)
		ft_putchar(n + '0', j);
	else
	{
		ft_putnbr_uu(n / 10, j);
		ft_putnbr_uu(n % 10, j);
	}
}

static int	chick_l(unsigned int n)
{
	int	x;

	x = 0;
	if (n <= 9)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

static int	*intt(unsigned int n, char *format, int *re)
{
	int	if_m;

	re[0] = git_n(format);
	re[1] = git_n_after_p(format);
	re[2] = git_n_after_p(format);
	if_m = 0 ;
	if_m = chick_l(n);
	if (n == 0 && check_poin(format))
		if_m = 0;
	re[3] = if_m;
	return (re);
}

static void	min1(unsigned int n, char *format, int *j, int *re)
{
	while (re[2] - re[3] > 0 && re[2] > re[3])
	{
		ft_putchar('0', j);
		re[2]--;
	}
	if (n != 0 || (!check_poin(format) && n == 0))
		ft_putnbr_uu(n, j);
	while ((re[0] - re[1] > 0 && re[0] > 0
			&& git_n(format) > re[3] && re[1] >= re[3])
		|| (re[1] < re[3] && re[0] - re[3] > 0 && re[0] > 0
			&& git_n(format) > re[3]))
	{
		ft_putchar(' ', j);
		re[0]--;
	}
}

void	ft_putnbr_u(unsigned int n, char *format, int *j)
{
	int	*re;

	re = malloc(sizeof(re) * 4);
	re = intt(n, format, re);
	if (check_maiees(format))
		min1(n, format, j, re);
	else
	{
		while ((re[0] - re[1] > 0 && re[0] > 0 
				&& git_n(format) > re[3] && re[2] >= re[3])
			|| (re[2] < re[3] && re[0] - re[3] > 0 && re[0] > 0
				&& git_n(format) > re[3]))
		{
			if (check_zero(format) && re[1] == 0 && !check_poin(format))
				ft_putchar('0', j);
			else
				ft_putchar(' ', j);
			re[0]--;
		}
		while (re[2] - re[3] > 0 && re[2]-- > re[3])
			ft_putchar('0', j);
		if (n != 0 || (!check_poin(format) && n == 0))
			ft_putnbr_uu(n, j);
	}
	free(re);
}
