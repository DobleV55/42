NAME=libft.a
CC=gcc
SRC=ft_memset.c ft_isalpha.c ft_isdigit.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c  ft_memset.c  ft_strlcat.c ft_strlen.c  ft_strrchr.c ft_toupper.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c  ft_strchr.c  ft_strlcpy.c ft_strncmp.c ft_tolower.c
OBJS=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror

all : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

.PHONY: all clean fclean re