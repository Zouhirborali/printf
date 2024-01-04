#include "ft_printf.h"




void	ft_putchar_p(char c ,char *format)
{
    int x = 0;
    int len =git_n(format);
    if(check_maiees(format))
    {
        ft_putchar(c);
        while(len  >0 &&  (len - 1)>0 ) 
        {
            ft_putchar('.');
            len--;
        }
    }
    else
    {
        while(len  >0 &&  (len - 1)>0 ) 
        {
            if(check_zero(format))
                ft_putchar('0');
            else
                ft_putchar('.');
            len--;
        }
        ft_putchar(c);
    }

}