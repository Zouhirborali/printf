#include "ft_printf.h"


static char * git_s(const char * format)
{
    int x =0;
	char * format2 = (char *)format;
	int pin =0;
	if(*format =='%')
		return "%";
    while(*format &&(*format == '#' || *format == '-' || *format == '+' || *format == '0' || *format == '.' || *format == ' '))
    {
        x++ ;
        format++;
   }
    while(*format &&((*format >= '0' && *format <= '9') || (*format =='.' && !pin)))
    {
		if(*format =='.')
			pin = 1;
        x++ ;
        format++;
   }
	if(*format == '%' || *format == 'c' || *format == 's' || *format == 'u' || *format == 'd' || *format == 'i' || *format == 'p' || *format == 'x' || *format == 'X')
   		return ft_substr(format2,0,x+1 );
	else
		return ft_substr(format2,0,x );
}

/////////////////////////////////////////////////////////////////////////////
static void check_flags(va_list args, char *format,int *j)
{
	
	char flag = *(format + ft_strlen(format)-1);
	if (flag == 's')
		ft_putstr(va_arg(args, char *),format,j);
	else if (flag == 'c')
		ft_putchar_p(va_arg(args, int),format,j);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(ft_itoa(va_arg(args, int)),format,j);
	else if (flag == 'u')
		ft_putnbr_u(va_arg(args, unsigned int),format,j);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, int), 'x',format,j);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, int), 'X',format,j);
	else if (flag == 'p')
		ft_putaddr(va_arg(args, void *),format,j);
	else if (flag == '%')
		ft_putchar(flag,j);
}

int ft_printf ( const char * format, ... )
{
    va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
    while (*format)
	{
		if (*format == '%' && *(format+1)!='\0')
		{
			format++;
			check_flags(args, git_s(format),&len);
			//printf("%s\n", git_s(format));
			format += (ft_strlen(git_s(format))-1);
			
		}
		else
			ft_putchar(*format,&len);
		format++;
		
	}
	va_end(args);
	return (len);

}

#include <limits.h>
int main()
{

 ft_printf(" %#x \n", 0);
 ft_printf(" %#x \n", LONG_MIN);
 ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
 ft_printf(" %#X \n", 0);
 ft_printf(" %#X \n", LONG_MIN);
 ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

printf("------------------\n");


printf(" %#x \n", 0);
printf(" %#x \n", LONG_MIN);
printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
printf(" %#X \n", 0);
printf(" %#X \n", LONG_MIN);
printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);






}
