#include "ft_printf.h"



static void	ft_putnbr_uu(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr_uu(n / 10);
		ft_putnbr_uu(n % 10);
	}
}

static int	chick_l(unsigned int n)
{
	int	x;

	x = 0;
	if (n <= 9 && n >= 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		x++; 
	}
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}
void	ft_putnbr_u(unsigned int n, char * format)
{
    int x =0;
    int len =git_n(format);
    int lens = git_n_after_p(format);
    int lens2 = git_n_after_p(format);
    int if_m ;
    if_m = chick_l(n);
    if(check_maiees(format))
    {
        while(lens2 - if_m>0 && lens2 >if_m && ft_itoa(n)[x]!='-')
        {
            ft_putchar('0');
            lens2--;
        }
        ft_putnbr_uu(n);
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens >=if_m)||(lens <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            ft_putchar(' ');
            len--;
        }
    }
    else
    {
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            if(check_zero(format) && lens == 0 && !check_poin(format))
                ft_putchar('0');
            else
                ft_putchar(' ');

            len--;
        }
        while(lens2 - if_m>0 && lens2 >if_m )
        {
            ft_putchar('0');
            lens2--;
        }
        ft_putnbr_uu(n);
    }
}