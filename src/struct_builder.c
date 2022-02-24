/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:16:18 by amajer            #+#    #+#             */
/*   Updated: 2022/02/24 16:29:57 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	struct_builder(unsigned long long tet, int t_width, int t_height, int piece_index)
{
	t_etrimino	tetrimino[26];

	piece_index = piece_index - 1;
	tetrimino[piece_index].value = tet;
	tetrimino[piece_index].width = t_width;
	tetrimino[piece_index].height = t_height;
	printf("\n\nstructure check:\n[index: %i]\n[width: %i]\n[height: %i]\n", tetrimino[piece_index].value, tetrimino[piece_index].width, tetrimino[piece_index].height);
}