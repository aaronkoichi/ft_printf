# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 12:10:45 by zlee              #+#    #+#              #
#    Updated: 2024/12/02 12:18:04 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_utils.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror 

CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft/ all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean

