/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:01:56 by amajer            #+#    #+#             */
/*   Updated: 2022/02/15 19:03:14 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** Utility function to get min-max values for get_piece.
** pos is a 4 dimensional array encoded as: xMin 0, xMax 1, yMin 2, yMax 3
*/
void	ft_measure_piece(char *str, int *positions, int i)
{
	int	tetris_width;
	int	tetris_height;

	positions[0] = 3;
	positions[1] = 0;
	positions[2] = 3;
	positions[3] = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < positions[0])
				positions[0] = i % 5;
			if (i % 5 > positions[1])
				positions[1] = i % 5;
			if (i / 5 < positions[2])
				positions[2] = i / 5;
			if (i / 5 > positions[3])
				positions[3] = i / 5;
		}
	}
	tetris_width = positions[1] - positions[0] + 1;
	tetris_height = positions[3] - positions[2] + 1;
}