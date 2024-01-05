#include "ft_printf.h"



void	ft_putnbr(char *s ,char * format,int*j)
{
    int x =0;
    int len =git_n(format);
    int lens = git_n_after_p(format);
    int lens2 = git_n_after_p(format);
    int if_m ;
    if (s[0]=='-')
        if_m = ft_strlen(s)-1;
    else
        if_m = ft_strlen(s);

    if(check_maiees(format))
    {
        if(check_sp(format) &&!check_pluse(format) && s[0]!='-')
        {
                ft_putchar(' ',j);
            len--;
        }
        else if (check_pluse(format)  || s[0]=='-')
        {
           if(s[0]!='-')
                ft_putchar('+',j);
            else
                ft_putchar('-',j);
            len--;
        }
        while(lens2 - if_m>0 && lens2 >if_m)
        {
            ft_putchar('0',j);
            lens2--;
        }
        while(s[x])
        {
            if(s[x] == '-' || s[x] == '+')
                x++;
            else
                ft_putchar(s[x++],j);
        }
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens >=if_m)||(lens <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            ft_putchar(' ',j);
            len--;
        }
    }
    else
    {
        if(check_sp(format) || check_pluse(format) ||s[0]=='-')
        {
            if  (!check_pluse(format) &&s[0]!='-')
                ft_putchar(' ',j);
            len--;
        }
        if ((check_pluse(format)||s[0]=='-') && check_zero(format) && lens ==0&&!check_poin(format))
        {
            if(s[0]!='-')
                ft_putchar('+',j);
            else
                ft_putchar('-',j);
        }
        while((len - lens> 0 && len > 0 && git_n(format) >if_m && lens2 >=if_m)||(lens2 <if_m&& len -if_m >0 &&len > 0 && git_n(format) >if_m))
        {
            if(check_zero(format) && lens == 0 && !check_poin(format))
                ft_putchar('0',j);
            else
                ft_putchar(' ',j);

            len--;
        }
        len=git_n(format);
        if (((check_pluse(format)||s[0]=='-')  && (!check_zero(format)||check_poin(format)))||(s[0]=='-' && !check_pluse(format) &&!check_zero(format)))
        {
            if(s[0]!='-')
                ft_putchar('+',j);
            else
                ft_putchar('-',j);
        }
        while(lens2 - if_m>0 && lens2 >if_m)
        {
            ft_putchar('0',j);
            lens2--;
        }

        while(s[x])
        {
            if(s[x] == '-' || s[x] == '+')
                x++;
            else
                ft_putchar(s[x++],j);
        }
    }
}