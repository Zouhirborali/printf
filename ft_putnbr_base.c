
#include "ft_printf.h"
static void	ft_putnbr_bb(unsigned int nbr, char Xx)
{
	unsigned int	base_len;
	char			*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len]);
	else
	{
		ft_putnbr_bb(nbr / base_len, Xx);
		ft_putnbr_bb(nbr % base_len, Xx);
	}
}
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

int  check_hash(char * format)
{
    int x =0;
    while(format[x])
    {
        while(format[x] &&(!(format[x] >= '0' && format[x] <= '9')&& format[x] != '.' && format[x] != '#')||format[x] =='0')
            x++;
        if(format[x] && format[x] == '#')
            return 1;
        return 0;
    }
    
    return 0;
}

void	ft_putnbr_base(unsigned int n, char Xx,char *format)
{
	int x =0;
    int len =git_n(format);
    int lens = git_n_after_p(format);
    int lens2 = git_n_after_p(format);
    int if_m ;
    printf("%d\n",len);
    printf("%d\n",lens);
    printf("zero %d\n",check_zero(format));


    chick_l(n,&if_m);
	if_m -=2;
    printf("i %d\n",if_m);

    if(check_maiees(format))
    {
		if(check_hash(format))
		{
			ft_putchar('0');
			ft_putchar(Xx);
			len-=2;
		}
        while(lens2 - if_m>0 && lens2 >if_m && ft_itoa(n)[x]!='-')
        {
            ft_putchar('0');
            lens2--;
        }
        ft_putnbr_bb(n,Xx);
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens >=if_m)||(lens <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            ft_putchar('.');
            len--;
        }
    }
    else
    {
		if(check_hash(format))
		{
			if((check_zero(format) && lens == 0 && !check_poin(format)))
			{
				ft_putchar('0');
				ft_putchar(Xx);
			}
			len-=2;
		}
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            if(check_zero(format) && lens == 0 && !check_poin(format))
                ft_putchar('0');
            else
                ft_putchar('.');

            len--;
        }
		if(check_hash(format) && !(check_zero(format) && lens == 0 && !check_poin(format)))
		{
			ft_putchar('0');
			ft_putchar(Xx);
		}
        while(lens2 - if_m>0 && lens2 >if_m )
        {
            ft_putchar('0');
            lens2--;
        }
        ft_putnbr_bb(n,Xx);
    }
}

