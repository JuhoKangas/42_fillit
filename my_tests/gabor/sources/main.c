/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/02/10 12:44:35 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fillit.h"
#include <stdio.h>
#include <stdint.h>

typedef struct s_tetri
{
	uint64_t		code;
	int				pos;
	char			letter;
	int				left;
	int				width;
	int				height;
}				t_tetri;


static void print_map(uint16_t map[16])
{
	int i = 0;
	int j = 0;
	uint16_t flag = 32768;

	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			if (map[i] & flag)
				printf("1 ");
			else
				printf("0 ");
			flag >>= 1;
			j++;
		}
		flag = 32768;
		printf("\n");
		i++;
	}
}

static void print_tetri(t_tetri *tetri, int index)
{
	uint64_t flag = 1;
	int i;
	int j;

	i = 0;
	flag  <<= 15;
	while (i < 4)
	{
		j = 0;
		while(j < 16)
		{
			if (flag & tetri[index].code >> 3)
				printf("1 ");
			else
				printf("0 ");
			if (j < 15)
				flag >>= 1;
			j++;
		}
		printf("\n");
		flag <<= 31;
		i++;
	}
}

int	main()
{
	//int			fd;
	int			count;
	int			size;
	t_tetri		tetri[27];
	uint16_t	map[16];
	char tet3[21] = "....\n.#..\n###.\n....\n";

	

	count = 0;

	tetri[count].code = 0;

	print_tetri(tetri, 0);
	printf("\n");
	print_tetri(tetri, 1);
	printf("\n");
	print_tetri(tetri, 2);

	printf("\n");
	print_map(map);
	printf("\n");
	print_board(tetri, size);

	return (0);
}
