/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:01:56 by amajer            #+#    #+#             */
/*   Updated: 2022/02/25 15:49:43 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// Utility function to get min-max values for get_piece.
// pos is a 2 dimensional array encoded as: xMin 0, xMax 1
int	ft_measure_width(char *str)
{
	int	positions[2];
	int	i;

	i = -1;
	positions[0] = 3;
	positions[1] = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < positions[0])
				positions[0] = i % 5;
			if (i % 5 > positions[1])
				positions[1] = i % 5;
		}
	}
	return (positions[1] - positions[0] + 1);
}

// pos is a 2 dimensional array encoded as: yMin 0, yMax 1

int	ft_measure_height(char *str)
{
	int	positions[2];
	int	i;

	i = -1;
	positions[0] = 3;
	positions[1] = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < positions[0])
				positions[0] = i / 5;
			if (i / 5 > positions[1])
				positions[1] = i / 5;
		}
	}
	return (positions[1] - positions[0] + 1);
}