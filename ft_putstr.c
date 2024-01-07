#include "ft_printf.h"



void	ft_putstr(char *s ,char * format,int*j)
{
    int x =0;
    int l =0;
    if (s == NULL)
    {
	if(git_n_after_p(format)>=6 ||(git_n_after_p(format)==0 && !check_poin(format)))
	        ft_putstr("(null)", format,j);
        else
            ft_putstr("\0", format,j);
        return;
    }
    int len =git_n(format);
    int lens = git_n_after_p(format);
    if((int)ft_strlen(s)> lens && lens !=0 && check_poin(format))
        l = lens;
    else if((int)ft_strlen(s) <= lens || (lens ==0 && !check_poin(format)))
        l = ft_strlen(s);
    //printf("%d",l);
    if(check_maiees(format))
    {
        while(s[x]&& (lens -1 >= x || (!check_poin(format) && lens ==0)))
            ft_putchar(s[x++],j);
        while(len>0 && len > l)
        {
            ft_putchar(' ',j);
            len--;
        }
    }
    else
    {
        
        //while((len  >0 && len > (int)ft_strlen(s) && lens>= (int)ft_strlen(s))||( (lens &&len  >0 && len > lens && lens< (int)ft_strlen(s))|| (!lens &&len  >0 && len > (int)ft_strlen(s) && lens< (int)ft_strlen(s))))
        while(len>0 && len > l)
        {
            if(check_zero(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);
            len--;
        }
        while(s[x]&& (lens -1 >= x || (!check_poin(format) && lens ==0)))
            ft_putchar(s[x++],j);
    }


}



