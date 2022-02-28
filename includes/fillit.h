/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:29:49 by amajer            #+#    #+#             */
/*   Updated: 2022/02/25 17:27:46 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft/libft.h"

typedef struct	s_etrimino
{
	unsigned long long	value;
	int					width;
	int					height;
	char				id;
}				t_etrimino;

int					ft_reader_function(int fd, t_etrimino *tetris);

t_etrimino 			build_piece(int piece_index, char *buff);

int					ft_validate_file(char *buff, int piece_index);
int					ft_validate_shape(char *piece_index);

int					ft_measure_height(char *str);
int					ft_measure_width(char *str);

unsigned long long	ft_string_to_ull(char *tet_str);
unsigned long long	up_shift(unsigned long long tetrimino);
unsigned long long	left_shift(uint64_t tetrimino);

unsigned long long 	set_bit(unsigned long long tet, int index);

void 	bin(unsigned long long n);
void	error(int i);

#endif