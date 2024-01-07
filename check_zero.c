#include "ft_printf.h"

int check_zero(char * format)
{
    int x =0;
    while(format[x])
    {
        while(format[x] &&!(format[x] >= '0' && format[x] <= '9')&& format[x] != '.')
            x++;
        while(format[x] == '0')
            return 1;
        return 0;
    }
    
    return 0;
}
