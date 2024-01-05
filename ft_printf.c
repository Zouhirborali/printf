#include "ft_printf.h"


char * git_s(const char * format)
{
    int x =0;
	char * format2 = (char *)format;
	int pin =0;
	if(*format =='%')
		return "%";
    while(*format &&(*format == '#' || *format == '-' || *format == '+' || *format == '0' || *format == '.' || *format == ' '))
    {
        x++ ;
        *format++;
   }
    while(*format &&((*format >= '0' && *format <= '9') || (*format =='.' && !pin)))
    {
		if(*format =='.')
			pin = 1;
        x++ ;
        *format++;
   }
	if( *format == 'c' || *format == 's' || *format == 'u' || *format == 'd' || *format == 'i' || *format == 'p' || *format == 'x' || *format == 'X')
   		return ft_substr(format2,0,x+1 );
	else
		return ft_substr(format2,0,x );
}

/////////////////////////////////////////////////////////////////////////////
void check_flags(va_list	args, char *format)
{
	int x =0;
	char flag = *(format + ft_strlen(format)-1);
	if (flag == 's')
		ft_putstr(va_arg(args, char *),format);
	else if (flag == 'c')
		ft_putchar_p(va_arg(args, int),format);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(ft_itoa(va_arg(args, int)),format);
	else if (flag == 'u')
		ft_putnbr_u(va_arg(args, unsigned int),format);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, int), 'x',format);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, int), 'X',format);
	else if (flag == 'p')
		ft_putaddr(va_arg(args, void *),format);
	else
	{
		ft_putchar('%');
		while(format[x])
			ft_putchar(format[x++]);
	}
}

int ft_printf ( const char * format, ... )
{
    va_list	args;
	int		len;

	len = 0;
    char * ff;
	va_start(args, format);
    while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flags(args, git_s(format));
			//printf("%s\n", git_s(format));
			format += (ft_strlen(git_s(format))-1);
			
		}
		else
			ft_putchar(*format);
		format++;
		
	}
	
	va_end(args);
	return (len);
}
int main ()
{
ft_printf("3%3d\n", 1);       
//ft_printf("%5u\n", 300);      
//ft_printf("%-5u\n", 300);     
//ft_printf("%05u\n", 300);     
//ft_printf("%.5u\n", 300);     
//ft_printf("%-5.5u\n", 300);   

printf("3%3d\n", 1);          // Default unsigned output: 300
//printf("%5u\n", 300);         // Field width 5, right-justified: "  300"
//printf("%-5u\n", 300);        // Field width 5, left-justified: "300  "
//printf("%05u\n", 300);        // Field width 5, zero-padded: "00300"
//printf("%.5u\n", 300);        // Precision 5, zero-padded: "00300"
//printf("%-5.5u\n", 300);    // Left-justified, minimum 5 digits with zero padding: "00300"
}
