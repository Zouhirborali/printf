#include "ft_printf.h"


static int  git_s(const char * format)
{
    int x =0;
	//char * format2 = (char *)format;
	int pin =0;
	if(*format =='%')
		return 1;
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
   		return x+1;
	else
		return x;
}

/////////////////////////////////////////////////////////////////////////////
char	*ft_strdup(const char *s1 ,	char *re)
{

	int		x;

	x = 0;
	re = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!re)
		return (NULL);
	while (s1[x])
	{
		re[x] = s1[x];
		x++;
	}
	re[x] = '\0';
	return (re);
}


static void check_flags(va_list args, char *format,int *j)
{
	char *re = NULL;
	char*rr=NULL;
	re = ft_strdup(format,re);
	char flag = *(re + ft_strlen(re)-1);
	if (flag == 's')
		ft_putstr(va_arg(args, char *),re,j);
	else if (flag == 'c')
		ft_putchar_p(va_arg(args, int),re,j);
	else if (flag == 'd' || flag == 'i')
	{
		rr =ft_itoa(va_arg(args, int),rr);
		ft_putnbr(rr,re,j);
	}
	else if (flag == 'u')
		ft_putnbr_u(va_arg(args, unsigned int),re,j);
	else if (flag == 'x')
		ft_putnbr_base(va_arg(args, int), 'x',format,j);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, int), 'X',format,j);
	else if (flag == 'p')
		ft_putaddr(va_arg(args, void *),format,j);
	else if (flag == '%')
		ft_putstr("%",format,j);
		//ft_putchar(flag,j);
	free(re);
	free(rr);
}

int ft_printf ( const char * format, ... )
{
    va_list	args;
	int		len;
	//char * buffer =NULL;
	len = 0;
	va_start(args, format);
    while (*format)
	{
		if (*format == '%' && *(format+1)!='\0')
		{
			format++;
			//buffer= malloc(sizeof(char) * (len + 1));
			check_flags(args, ft_substr(format,0,git_s(format)),&len);////////////////////////
			//printf("|%s|\n", ft_substr(format,0,2));
			//printf("|d=%d|\n", git_s(format));
			format += (git_s(format)-1);
			//free(buffer);
		}
		else
			ft_putchar(*format,&len);
		format++;
	}
	

	va_end(args);
	return (len);

}
// int main ()
// {
//  ft_printf("%020.5u\n", 1024u);


// printf("---------------------------\n");


// printf("%020.5u\n", 1024u);

// }