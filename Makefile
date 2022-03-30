# -*- MakeFile -*-

NAME	= libftprintf.a 
LIB		= ./libft
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= 	ft_printf.c \
			src/ft_printf_char.c \
			src/ft_printf_hex.c \
			src/ft_printf_nbr.c \
			src/ft_printf_percent.c \
			src/ft_printf_pointer.c \
			src/ft_printf_selector.c \
			src/ft_printf_string.c \
			src/ft_printf_unsigned_int.c


OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB)
	mv $(LIB)/libft.a libftprintf.a
	ar -crs $(NAME) $^

clean: 
	rm -f *.o *.out src/*.o && make -C $(LIB) clean

fclean: clean
	rm -f $(NAME) && make -C $(LIB) fclean

re:	clean fclean all


.PHONY:
	all clean fclean re bonus