/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:29:49 by amajer            #+#    #+#             */
/*   Updated: 2022/02/15 18:16:48 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "libft/libft.h"

void	ft_validate_file(char *buff, int pieces);
void	error(int i);
int		ft_validate_piece(char *piece);
void	ft_measure_piece(char *str, int *positions, int i);

#endif