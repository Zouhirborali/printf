#include "ft_printf.h"



void	ft_putstr(char *s ,char * format,int*j)
{
    int x =0;
    if (s == NULL)
	ft_putstr("(null)", format,j);
    int len =git_n(format);
    int lens = git_n_after_p(format);
    if(check_maiees(format))
    {
        while(s[x]&& (lens -1 >= x || lens ==0))
            ft_putchar(s[x++],j);
        while(len  >0 && (((len - lens)>0 && lens>0) || (len - ft_strlen(s))>0 && lens ==0) )
        {
            ft_putchar(' ',j);
            len--;
        }
    }
    else
    {
        while(len  >0 && (((len - lens)>0 && lens>0) || (len - ft_strlen(s))>0 && lens ==0) )
        {
            if(check_zero(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);
            len--;
        }
        while(s[x]&& (lens -1 >= x || lens ==0))
            ft_putchar(s[x++],j);
    }


}


