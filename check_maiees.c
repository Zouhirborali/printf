#include "ft_printf.h"

int check_maiees(char * format)
{
    int x =0;
    while(format[x])
    {
        if(format[x]=='-')
            return 1;
        x++;
    }
    return 0;
}