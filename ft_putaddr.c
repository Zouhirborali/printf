/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:32:21 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 18:33:47 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	chick_l(unsigned long int nbr, int *x)
{
	if (nbr < 16)
		(*x)++;
	else
	{
		chick_l(nbr / 16, x);
		chick_l(nbr % 16, x);
	}
}

static int	*intt(void *addr, char *format, int *re)
{
	int	if_m;

	re[0] = git_n(format);
	re[1] = git_n_after_p(format);
	re[2] = git_n_after_p(format);
	if_m = 0 ;
	chick_l((unsigned long int)addr, &if_m);
	re[3] = if_m;
	return (re);
}

static void	min1(void *addr, char *format, int *j, int *re)
{
	if (check_pluse(format))
		ft_putchar('+', j);
	else if (check_sp(format))
		ft_putchar(' ', j);
	ft_putchar('0', j);
	ft_putchar('x', j);
	re[0] -= 2;
	if (check_pluse(format) || check_sp(format))
		(re[0])--;
	while (re[0] - re[3] > 0 && re[1] > re[3])
	{
		ft_putchar('0', j);
		(re[1])--;
	}
	ft_putaddr_hex((unsigned long int)addr, 'x', j);
	while ((re[0] - re[1] > 0 && re[0] > 0 && git_n(format) > re[3] 
			&& re[2] >= re[3]) || (re[2] < re[3] && re[0] - re[3] > 0 
			&&re[0] > 0 && git_n(format) > re[3]))
	{
		ft_putchar(' ', j);
		re[0]--;
	}
}

static void	pl1(char *format, int *j, int *re)
{
	if ((check_zero(format) && re[1] == 0 && !check_poin(format)))
	{
		if (check_pluse(format))
			ft_putchar('+', j);
		ft_putchar('0', j);
		ft_putchar('x', j);
	}
	re[0] -= 2;
	if (check_pluse(format))
		re[0]--;
	while ((re[0] - re[1] > 0 && re[0] > 0 && git_n(format) > re[3] && 
			re[2] >= re[3]) || (re[2] < re[3] && re[0] - re[3] > 0 
			&&re[0] > 0 && git_n(format) > re[3]))
	{
		if (check_zero(format) && re[1] == 0 && !check_poin(format))
			ft_putchar('0', j);
		else
			ft_putchar(' ', j);
		re[0]--;
	}
}

void	ft_putaddr(void *addr, char *format, int *j)
{
	int	*re;

	re = malloc(sizeof(re) * 4);
	re = intt(addr, format, re);
	if (check_maiees(format))
		min1(addr, format, j, re);
	else
	{
		pl1(format, j, re);
		if (!(check_zero(format) && re[1] == 0 && !check_poin(format)))
		{
			if (check_pluse(format))
				ft_putchar('+', j);
			ft_putchar('0', j);
			ft_putchar('x', j);
		}
		while (re[2] - re[3] > 0 && re[2] > re[3])
		{
			ft_putchar('0', j);
			re[2]--;
		}
		ft_putaddr_hex((unsigned long int)addr, 'x', j);
	}
	free(re);
}
