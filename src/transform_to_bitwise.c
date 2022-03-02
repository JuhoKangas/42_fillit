/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_bitwise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:12:35 by amajer            #+#    #+#             */
/*   Updated: 2022/03/02 15:40:31 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void bin(unsigned long long n)
{
	int i = 15;
	while (i > -1)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");
					//second line
	i = 31;
	while (i > 15)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
			i--;
	}
	printf("\n");
					//third line
	i = 47;
	while (i > 31)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");
					//fourth line
	i = 63;
	while (i > 47)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");

}

unsigned long long	left_shift(unsigned long long tetrimino)
{
	int	i;

	i = 3;
	//printf("\nbefore left shift\n");
	//bin(tetrimino);
//	printf("\n");
	while (i-- > 0)
		if (!(tetrimino & 1ULL << 15) && !(tetrimino & 1ULL << 31) && \
			 !(tetrimino & 1ULL << 47) && !(tetrimino & 1ULL << 63))
			tetrimino = tetrimino << 1;
	//bin(tetrimino);
	return (tetrimino);
}

unsigned long long	up_shift(unsigned long long tetrimino)
{
	int	i;

	i = 3;
//	printf("\n");
	while (i-- > 0)
		if (!(tetrimino & 1ULL << 15) && !(tetrimino & 1ULL << 14) && \
			 !(tetrimino & 1ULL << 13) && !(tetrimino & 1ULL << 12))
			tetrimino = tetrimino >> 16;
	return (left_shift(tetrimino));
}

unsigned long long set_bit(unsigned long long tet, int index)
{
	int	posix;
	int	posiy;
	
	posix = index % 5;
	posiy = index / 5;
	tet = (1L << (16 * (posiy + 1) - 1 - posix)) | tet;
	return (tet);
}

unsigned long long	ft_string_to_ull(char *tet_str)
{
	unsigned long long	tetrimino;
	int					i;

	tetrimino = 0;
	i = 0;
	while(tet_str[i] != 0)
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