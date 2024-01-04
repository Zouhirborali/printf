#include "ft_printf.h"

int check_poin(char * format)
{
    int x =0;
    while(format[x])
    {
        while(format[x] && format[x] != '.')
            x++;
        while(format[x] && format[x] == '.')
            return 1;
        return 0;
    }
    
    return 0;
}
