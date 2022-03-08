/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:52:23 by jkangas           #+#    #+#             */
/*   Updated: 2022/03/08 16:27:07 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 * Calculates the smalles possible map for the pieces by taking
 * a square root of the sum of the blocks in tetriminos
 */

int	get_mapsize(const int pieces)
{
	int	size;

	size = ft_sqrt(pieces * 4);
	if (!size)
	{
		size = 3;
		while (size * size < pieces * 4)
			size++;
	}
	return (size);
}

/*
 * Tries out every combination using backtracking algorithm to find
 * the smallest possible map to fit all the tetriminoes. Using 
 * bitwise operations to fill the map and saving the solution to the
 * map given as a parameter.
 */

int	fill_map(uint16_t *map, t_etrimino *tet, const int size)
{
	if (tet->id == 0)
		return (1);
	tet->y = 0;
	while (tet->y <= size - tet->height)
	{
		tet->x = 0;
		while (tet->x <= size - tet->width)
		{
			if (!(*(uint64_t *)(map + tet->y) & (tet->value >> tet->x)))
			{
				*(uint64_t *)(map + tet->y) ^= (tet->value >> tet->x);
				if (fill_map(map, tet + 1, size))
					return (1);
				*(uint64_t *)(map + tet->y) ^= (tet->value >> tet->x);
			}
			tet->x++;
		}
		tet->y++;
	}
	return (0);
}

/*
 * Main function for solving the map. Returns the size of
 * the map to the function that called it for printing the solution.
 */

int	solve_map(t_etrimino *tetris, const int pieces)
{
	int			size;
	uint16_t	map[16];

	size = get_mapsize(pieces);
	ft_bzero(map, sizeof(*map) * 16);
	while (!fill_map(map, tetris, size))
	{
		ft_bzero(map, sizeof(*map) * 16);
		++size;
	}
	return (size);
}
