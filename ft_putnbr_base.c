
#include "ft_printf.h"
static void	ft_putnbr_bb(unsigned int nbr, char Xx,int *j)
{
	unsigned int	base_len;
	char			*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len],j);
	else
	{
		ft_putnbr_bb(nbr / base_len, Xx,j);
		ft_putnbr_bb(nbr % base_len, Xx,j);
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
        while((format[x] &&(!(format[x] >= '0' && format[x] <= '9')&& format[x] != '.' && format[x] != '#'))||format[x] =='0')
            x++;
        if(format[x] && format[x] == '#')
            return 1;
        return 0;
    }
    
    return 0;
}

void	ft_putnbr_base(unsigned int n, char Xx,char *format,int *j)
{
	
    int len =git_n(format);
    int lens = git_n_after_p(format);
    int lens2 = git_n_after_p(format);
    int if_m =0;
    chick_l(n,&if_m);
    if (n == 0&& check_poin(format))
    	if_m =0;
    if(check_maiees(format))
    {
		if(check_hash(format)&&n!= 0)
		{
			ft_putchar('0',j);
			ft_putchar(Xx,j);
			len-=2;
		}
        while(lens2 - if_m>0 && lens2 >if_m )
        {
            ft_putchar('0',j);
            lens2--;
        }
	if(n!=0 || (!check_poin(format) && n==0) )
        	ft_putnbr_bb(n,Xx,j);
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens >=if_m)||(lens <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            ft_putchar(' ',j);
            len--;
        }
    }
    else
    {
		if(check_hash(format)&&n!= 0)
		{
			if((check_zero(format) && lens == 0 && !check_poin(format)))
			{
				ft_putchar('0',j);
				ft_putchar(Xx,j);
			}
				len-=2;
		}
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            if(check_zero(format) && lens == 0 && !check_poin(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);

            len--;
        }
		if(n!=0 &&check_hash(format) && !(check_zero(format) && lens == 0 && !check_poin(format)))
		{
			ft_putchar('0',j);
			ft_putchar(Xx,j);
		}
        while(lens2 - if_m>0 && lens2 >if_m )
        {
            ft_putchar('0',j);
            lens2--;
        }
	if(n!=0 || (!check_poin(format) && n==0) )
       		ft_putnbr_bb(n,Xx,j);
    }
}

