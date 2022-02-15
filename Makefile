# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 15:58:49 by amajer            #+#    #+#              #
#    Updated: 2022/02/15 18:29:58 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
CFILES := main.c error.c get_next_line.c
CC := gcc
CFLAGS := -Wall -Wextra -Werror
OBJ := main.o error.o get_next_line.o
RM := /bin/rm -f
INCLUDES := -I./libft
HEADER = $(NAME).h
LIBFT := -L./libft -lft

all: $(NAME)

$(NAME): $(CFILES) $(HEADER)
	$(MAKE) -C libft re
	$(CC) $(CFLAGS) $(CFILES) $(INCLUDES) $(LIBFT) -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C libft re

.PHONY: all clean fclean re
