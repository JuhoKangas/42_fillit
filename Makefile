# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 15:58:49 by amajer            #+#    #+#              #
#    Updated: 2022/03/17 14:41:10 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME := fillit

# Directories
SRC_DIR := ./src
INC_DIR := ./includes
OBJ_DIR := ./obj

# src / obj files
SRC := main.c error.c measure.c reader.c \
		validator.c transform_to_bitwise.c \
		solver.c printer.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRC))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Libraries
LIBFT := -L./libft -lft
INCLUDES := -I./libft
INCLUDES += -I$(INC_DIR)

RM := /bin/rm -f
RMDIR := /bin/rm -rf

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	$(MAKE) -C libft
	$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ)
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) -C libft re
