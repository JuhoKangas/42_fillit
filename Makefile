# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 15:58:49 by amajer            #+#    #+#              #
#    Updated: 2022/02/21 15:40:15 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME := fillit

# Directories
SRC_DIR := ./src
INC_DIR := ./includes

# src / obj files
SRC := main.c error.c measure.c reader.c validator.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRC))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Libraries
LIBFT := -L./libft -lft
INCLUDES := -I./libft -I$(INC_DIR)

RM := /bin/rm -f
RMDIR := /bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBFT) -o $@

clean:
	@$(MAKE) -C libft clean
	@$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C libft re
