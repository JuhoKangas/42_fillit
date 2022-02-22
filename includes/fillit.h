/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:29:49 by amajer            #+#    #+#             */
/*   Updated: 2022/02/22 17:59:15 by amajer           ###   ########.fr       */
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

void				ft_reader_function(int fd, int ret);

void				ft_validate_file(char *buff, int pieces);
int					ft_validate_shape(char *piece, int i);

void				ft_measure_piece(char *str, int *positions, int i, int piece_number);

void				ft_string_to_ull(char *tet_str, int t_width, int t_height, int piece_number);
unsigned long long	up_shift(unsigned long long tetrimino);
unsigned long long	left_shift(uint64_t tetrimino);

void	struct_builder(unsigned long long tet, int t_width, int t_height, int piece_number);

unsigned long long set_bit(unsigned long long tet, int index);


void bin(unsigned long long n);
void	error(int i);

#endif