# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 15:58:49 by amajer            #+#    #+#              #
#    Updated: 2022/02/11 14:51:17 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFILES = main.c error.c get_next_line.c
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./libft/
LIB = -L ./libft -lft

all: $(NAME)

$(NAME): $(CFILES)
	make -C ./libft re
	gcc $(FLAGS) $(INCLUDES) $(CFILES) $(LIB) -o $(NAME)

clean:
	make -C ./libft clean

fclean:
	make -C ./libft fclean
	rm -f $(NAME)

re:
	make -C ./libft re
	fclean
	all
