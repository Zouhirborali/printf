
# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(char *s, char *format, int*j);
void	ft_putnbr_u(unsigned int n, char *format, int*j);
char	*ft_itoa(int n, char*num);
void	ft_putchar(char c, int *j);
void	ft_putchar_p(char c, char *format, int *j);
void	ft_putstr(char *s, char *format, int*j);
char	*ft_substr(const char *s, unsigned int start, size_t len, char	*buffer);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned int n, char Xx, char *format, int *j);
void	ft_putaddr(void *addr, char *format, int *j);
char	*ft_strdup(const char *s1,	char *re);
void	ft_putaddr_hex(unsigned long int nbr, char Xx, int *j);
//
int		git_n(char *format);
int		check_zero(char *format);
int		check_sp(char *format);
int		check_pluse(char *format);
int		git_n_after_p(char *format);
int		check_maiees(char *format);
int		check_poin(char *format);
int	check_hash(char *format);

//void	ft_putnbr_base(unsigned int nbr, char Xx, int *len);
//void	ft_putaddr(void *addr, int *len);

#endif