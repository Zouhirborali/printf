#include "ft_printf.h"

int check_sp(char * format)
{
    int x =0;
    while(format[x])
    {
        while((format[x] &&(!(format[x] >= '0' && format[x] <= '9')&& format[x] != '.' && format[x] != ' '))||format[x] =='0')
            x++;
        if(format[x] && format[x] == ' ')
            return 1;
        return 0;
    }
    
    return 0;
}
