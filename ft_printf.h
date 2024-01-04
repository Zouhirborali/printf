#ifndef  FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(char *s ,char * format);
void	ft_putnbr_u(unsigned int n , char * format);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putchar_p(char c ,char *format);
void	ft_putstr(char *s ,char * format);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned int n, char Xx,char *format);
void	ft_putaddr(void *addr,char *format);


int git_n(char * format);
int check_zero(char * format);
int check_sp(char * format);
int check_pluse(char * format);
int git_n_after_p(char * format);
int check_maiees(char * format);
int check_poin(char * format);

//void	ft_putnbr_base(unsigned int nbr, char Xx, int *len);
//void	ft_putaddr(void *addr, int *len);

#endif