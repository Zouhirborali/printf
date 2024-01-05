NAME	= libftprintf.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
src = check_maiees.c check_pluse.c check_poin.c check_sp.c\
	check_zero.c ft_itoa.c ft_printf.c ft_putaddr.c ft_putchar_p.c\
	ft_putchar.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr.c\
	ft_putstr.c ft_strlen.c ft_strlen.c git_n_after_p.c git_n.c\
OBJS=$(src:.c=.o)
all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS) -I ./
bonus:all

clean:
	rm -rf *.o
fclean:clean
	rm -rf $(NAME)
	
re:fclean all

.PHONY: all bonus clean fclean re;