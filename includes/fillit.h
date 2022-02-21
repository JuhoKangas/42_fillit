/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:29:49 by amajer            #+#    #+#             */
/*   Updated: 2022/02/21 17:31:41 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "../libft/libft.h"

void	ft_reader_function(int fd, int ret);

void	ft_validate_file(char *buff, int pieces);
int		ft_validate_shape(char *piece, int i);

void	ft_measure_piece(char *str, int *positions, int i);

void	ft_string_to_array(char *str, int i, int j, int z);
char	**allocate_array();
void	ft_array_to_integer(char **tetrimino_array);
unsigned long long set_bit(unsigned long long tet, int index);


void bin(unsigned long long n);
void	error(int i);

#endif