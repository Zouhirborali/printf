/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zbakkas@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:18 by zbakkas           #+#    #+#             */
/*   Updated: 2024/01/10 17:30:07 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	git_cha(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'u' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

static int	git_s(const char *format)
{
	int	x;
	int	pin;

	x = 0;
	pin = 0;
	if (*format == '%')
		return (1);
	while (*format && (*format == '#' || *format == '-' || *format == '+' 
			|| *format == '0' || *format == '.' || *format == ' '))
	{
		x++ ;
		format++;
	}
	while (*format && ((*format >= '0' && *format <= '9') 
			|| (*format == '.' && !pin)))
	{
		if (*format == '.')
			pin = 1;
		x++ ;
		format++;
	}
	return (x + git_cha(*format));
}

static void	git_next_flags(va_list args, char *re, int *j, char flag)
{
	if (flag == 'x')
		ft_putnbr_base(va_arg(args, int), 'x', re, j);
	else if (flag == 'X')
		ft_putnbr_base(va_arg(args, int), 'X', re, j);
	else if (flag == 'p')
		ft_putaddr(va_arg(args, void *), re, j);
	else if (flag == '%')
		ft_putstr("%", re, j);
}

static void	check_flags(va_list args, char *format, int *j)
{
	char	*re;
	char	*rr;
	char	flag;

	rr = NULL;
	re = NULL;
	re = ft_strdup(format, re);
	flag = *(re + ft_strlen(re)-1);
	if (flag == 's')
		ft_putstr(va_arg(args, char *), re, j);
	else if (flag == 'c')
		ft_putchar_p(va_arg(args, int), re, j);
	else if (flag == 'd' || flag == 'i')
	{
		rr = ft_itoa(va_arg(args, int), rr);
		ft_putnbr(rr, re, j);
	}
	else if (flag == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), re, j);
	else if (flag == 'x' || flag == 'X' || flag == 'p' || flag == '%')
		git_next_flags(args, re, j, flag);
	free(re);
	free(rr);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	char	*l;

	len = 0;
	l = NULL;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			l = malloc(git_s(format) + 1);
			l = ft_substr(format, 0, git_s(format), l);
			check_flags(args, l, &len);
			format += (git_s(format) - 1);
			free(l);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
