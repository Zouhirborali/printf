#include "ft_printf.h"

void	ft_putchar(char c,int *j)
{
    write(1, &c, 1);
    (*j)++;
}