# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2024/10/31 13:42:51 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

LIB = lib/ft_strlen.c lib/ft_putstr.c lib/ft_putchar.c lib/ft_strlcpy.c lib/ft_strlcat.c lib/ft_strdup.c lib/ft_atoi.c lib/ft_itoa.c lib/ft_putnbr.c 
SRCS = srcs/main.c
HEADERS = ft_printf.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	ar -rsc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re