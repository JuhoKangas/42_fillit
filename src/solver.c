/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:52:23 by jkangas           #+#    #+#             */
/*   Updated: 2022/03/02 15:37:06 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	get_mapsize(const int pieces)
{
	int	size;

	size = ft_sqrt(pieces * 4);
	if(!size)
	{
		size = 3;

		while (size * size < pieces * 4)
			size++;
	}
	return (size);
} 

int	fill_map(uint16_t *map, t_etrimino *tetris, const int size)
{
	if (tetris->id == 0)
		return (1);
	tetris->y = 0;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = 0;
		while (tetris->x <= size - tetris->width)
		{
			if (!(*(uint64_t *)(map + tetris->y) & (tetris->value >> tetris->x)))
			{
				*(uint64_t *)(map + tetris->y) ^= (tetris->value >> tetris->x);
				if (fill_map(map, tetris + 1, size))
					return (1);
				*(uint64_t *)(map + tetris->y) ^= (tetris->value >> tetris->x);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	return (0);
}

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