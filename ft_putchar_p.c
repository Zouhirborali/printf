#include "ft_printf.h"




void	ft_putchar_p(char c ,char *format,int *j)
{
    int x = 0;
    int len =git_n(format);
    if(check_maiees(format))
    {
        ft_putchar(c,j);
        while(len  >0 &&  (len - 1)>0 ) 
        {
            ft_putchar(' ',j);
            len--;
        }
    }
    else
    {
        while(len  >0 &&  (len - 1)>0 ) 
        {
            if(check_zero(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);
            len--;
        }
        ft_putchar(c,j);
    }

}