/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:29:49 by amajer            #+#    #+#             */
/*   Updated: 2022/02/16 14:24:48 by jkangas          ###   ########.fr       */
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
void	error(int i);

#endif