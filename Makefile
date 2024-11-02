# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2024/11/02 11:57:52 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

PATH_LIB = lib/
PATH_SRCS = srcs/

LIB = ft_strlen.c ft_putstr.c ft_putchar.c ft_putnbr_base.c
SRCS = ft_printf.c ft_convert.c ft_print_memory.c
HEADERS = ft_printf.h

LIB_OBJS = $(addprefix $(PATH_LIB), $(LIB:.c=.o))
SRCS_OBJS = $(addprefix $(PATH_SRCS), $(SRCS:.c=.o))
OBJS = $(LIB_OBJS) $(SRCS_OBJS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	ar -rsc $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
