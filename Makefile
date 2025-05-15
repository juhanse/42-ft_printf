# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhanse <juhanse@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 17:16:52 by juhanse           #+#    #+#              #
#    Updated: 2025/05/16 01:34:31 by juhanse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

OBJDIR = objs/

LIB = lib/ft_strlen.c lib/ft_putstr.c lib/ft_putchar.c lib/ft_putnbr_base.c
SRCS = srcs/ft_convert.c srcs/ft_print_memory.c
FILES = ft_printf.c $(SRCS) $(LIB)

OBJS = $(addprefix $(OBJDIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rsc $(NAME) $(OBJS)
	@echo "$(COLOUR_GREEN)Compiled ✅$(COLOUR_END)"

$(OBJDIR)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	@echo "$(COLOUR_RED)Cleaned 🧹$(COLOUR_END)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOUR_RED)Cleaned all 🧹$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
