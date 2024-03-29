NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Werror -Wextra -I.
SRCS = ft_printf.c ft_putstr.c ft_putchar.c ft_putx.c printing_numbers.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
