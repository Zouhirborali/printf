CC = cc
NAME	= libftprintf.a
SRCS = check_maiees.c check_pluse.c check_poin.c check_sp.c\
	check_zero.c ft_itoa.c ft_printf.c ft_putaddr.c ft_putchar_p.c\
	ft_putchar.c ft_putnbr_base.c ft_putnbr_u.c ft_putnbr.c\
	ft_putstr.c ft_strlen.c ft_strlen.c git_n_after_p.c git_n.c ft_substr.c ft_strdup.c ft_putaddr_hex.c check_hash.c\

OBJS	= ${SRCS:%.c=%.o}

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS) ft_printf.h
	ar rc $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus:all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

