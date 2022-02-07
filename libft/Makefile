# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 13:55:41 by jkangas           #+#    #+#              #
#    Updated: 2021/12/10 19:36:42 by jkangas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -Wall -Wextra -Werror
INCLUDES = libft.h
STR_SRC = ft_strlen \
		ft_strdup \
		ft_strcpy \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strtrim \
		ft_strsub \
		ft_strequ \
		ft_strnequ \
		ft_strjoin \
		ft_strequ \
		ft_strsplit \
		ft_itoa \
		ft_tolower \
		ft_toupper \
		ft_wordcount \

MEM_SRC = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_memalloc \
		ft_memdel \

PUT_SRC = ft_putchar \
		ft_putstr \
		ft_putnbr \
		ft_putendl \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \

LST_SRC = ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap \

MATH_SRC = ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_abs \
		ft_isspace \
		ft_isupper \
		ft_islower \

SRC = $(STR_SRC) \
		$(MEM_SRC) \
		$(PUT_SRC) \
		$(LST_SRC) \
		$(MATH_SRC) \

SRCS = $(addsuffix .c, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME):
	@$(GCC) -c $(SRCS) -I$(INCLUDES)
	@echo "Files compiled"
	@ar rcs $(NAME) $(OBJ)
	@echo "Library 'libft.a' created"

clean:
	@rm -f $(OBJ)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
