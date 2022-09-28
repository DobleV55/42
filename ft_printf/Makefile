NAME = libftprintf.a
CC = gcc
SRC = ft_printf.c

OBJS=$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) -c $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
