NAME = libftprintf.a

LIB = libft.a

SRC = ft_printf.c

OBJS := $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS) $(LIB)
	ar rcs $@ $(OBJS) libft/$(LIB)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS) 
	cd libft && make clean

fclean : clean
	rm -rf $(NAME)
	cd libft && make fclean

re : fclean all

$(LIB):
	cd libft && make all

.PHONY : all clean fclean re

