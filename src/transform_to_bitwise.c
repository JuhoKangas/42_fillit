/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_bitwise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:12:35 by amajer            #+#    #+#             */
/*   Updated: 2022/03/08 16:35:45 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Shifts the tetrimino to the leftmost position in the X axis
 */

unsigned long long	left_shift(unsigned long long tetrimino)
{
	int	i;

	i = 3;
	while (i-- > 0)
		if (!(tetrimino & 1ULL << 15) && !(tetrimino & 1ULL << 31) && \
			!(tetrimino & 1ULL << 47) && !(tetrimino & 1ULL << 63))
			tetrimino = tetrimino << 1;
	return (tetrimino);
}

/*
 * Shifts the tetrimino to the upmost position in the Y axis
 */

unsigned long long	up_shift(unsigned long long tetrimino)
{
	int	i;

	i = 3;
	while (i-- > 0)
		if (!(tetrimino & 1ULL << 15) && !(tetrimino & 1ULL << 14) && \
			!(tetrimino & 1ULL << 13) && !(tetrimino & 1ULL << 12))
			tetrimino = tetrimino >> 16;
	return (left_shift(tetrimino));
}

/*
 * Calculates the x and y coordinates for the bit to set from
 * the index of the block.
 */

unsigned long long	set_bit(unsigned long long tet, int index)
{
	int	posix;
	int	posiy;

	posix = index % 5;
	posiy = index / 5;
	tet = (1L << (16 * (posiy + 1) - 1 - posix)) | tet;
	return (tet);
}

/*
 * Main function in converting the tetrimino to corresponding bits.
 * Returns the tetrimino in bitwise arrangement.
 */

unsigned long long	ft_string_to_ull(char *tet_str)
{
	unsigned long long	tetrimino;
	int					i;

	tetrimino = 0;
	i = 0;
	while (tet_str[i] != 0)
	{
		if (tet_str[i] == '\n')
			i++;
		if (tet_str[i] == '#')
			tetrimino = set_bit(tetrimino, i);
		i++;
	}
	tetrimino = up_shift(tetrimino);
	return (tetrimino);
}
