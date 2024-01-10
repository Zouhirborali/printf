
#include "ft_printf.h"

static void	chick_l(unsigned int nbr,int *x)
{

	if (nbr < 16)
		(*x)++;
	else
	{
		chick_l(nbr / 16,x);
		chick_l(nbr % 16, x);
	}
}



static int	*intt(unsigned int n, char *format, int *re)
{
	int	if_m;

	re[0] = git_n(format);
	re[1] = git_n_after_p(format);
	re[2] = git_n_after_p(format);
	if_m = 0 ;
	chick_l(n,&if_m);
	if (n == 0&& check_poin(format))
		if_m =0;
	re[3] = if_m;
	re[4] = check_hash(format);
	re[5] = check_poin(format);
	re[6] = git_n(format);
	re[7] = check_zero(format);
	return (re);
}

void	min1(unsigned int n, char Xx, int *j, int *re)
{
	if (re[4] && n != 0)
	{
		ft_putchar('0', j);
		ft_putchar(Xx, j);
		re[0] -= 2;
	}
	while (re[2] - re[3] > 0 && re[2] > re[3])
	{
		ft_putchar('0', j);
		re[2]--;
	}
	if (n!=0 || (!re[5] && n == 0))
		ft_putaddr_hex(n, Xx, j);
	while ((re[0] - re[1] > 0 && re[0] > 0 && re[6] > re[3] && re[1] >= re[3])
		|| (re[1] < re[3] && re[0] - re[3] > 0 && 
			re[0] > 0 && re[6] > re[3]))
	{
		ft_putchar(' ', j);
		re[0]--;
	}
}

void	pl1(unsigned int n, char Xx, int *j, int *re)
{
	if (re[4] && n != 0)
	{
		if ((re[7] && re[1] == 0 && !re[5]))
		{
			ft_putchar('0', j);
			ft_putchar(Xx, j);
		}
		re[0] -= 2;
	}
	while ((re[0] - re[1] > 0 && re[0] > 0 && re[6] > re[3] && re[2]  >= re[3])
		|| (re[2] < re[3] && re[0] - re[3] > 0 &&re[0] > 0 && re[6] > re[3]))
	{
		if (re[7] && re[1] == 0 && !re[5])
			ft_putchar('0', j);
		else
			ft_putchar(' ', j);
		re[0]--;
	}
	if (n != 0 && re[4] && !(re[7] && re[1] == 0 && !re[5]))
	{
		ft_putchar('0', j);
		ft_putchar(Xx, j);
	}
}

void	ft_putnbr_base(unsigned int n, char Xx, char *format, int *j)
{
	int	*re;

	re = malloc(sizeof(re) * 6);
	re = intt(n, format, re);
	if (check_maiees(format))
	{
		min1(n, Xx, j, re);
	}
	else
	{
		pl1(n, Xx, j, re);
		while (re[2] - re[3] > 0 && re[2] > re[3])
		{
			ft_putchar('0', j);
			re[2]--;
		}
		if (n != 0 || (!check_poin(format) && n == 0))
			ft_putaddr_hex(n, Xx, j);
	}
	free(re);
}

