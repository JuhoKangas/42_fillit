/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:14:53 by amajer            #+#    #+#             */
/*   Updated: 2022/02/10 13:24:33 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

/*
unsigned long long shift_tetrimino(unsigned long long tetrimino)
{

}
*/
/*void bin(unsigned long long n)
{
	int i = 64;

	while (i--)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		if (i % 4 == 0 && i != 0)
			printf("\n");
	}
}*/

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

static void print_tetri( char *tetri, int index)
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
			if (flag & tetri[index] >> 3)
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
/*
unsigned long long set_bit(unsigned long long tet, int posix)
{
	tet = (1ULL << posix) | tet;
	return (tet);
}
*/
int	main()
{
	char tet1[21] = "...#\n...#\n...#\n...#\n";
	//char tet2[21] = "....\n..##\n...#\n...#\n";
	//char tet3[21] = "....\n.#..\n###.\n....\n";
	///char tet4[21] = "....\n.###\n..#.\n....\n";
	//char tet5[21] = "....\n####\n....\n....\n";

	//unsigned long long tetrimino = 0;
	int i = 0;
	int j = 21;

	print_map(14141302829943357440);




/*
			// TEST NUMBER	//
	int n = 1;
	
			//	TEST 1	//
	if (n == 1)
	{
		while(tet1[i] != 0)
		{
			if (tet1[i] == '\n')
				i++;
			if (tet1[i] == '#')
			{
					//tetrimino = set_bit(tetrimino, j);
					print_tetri(tet1, j);
			}
			i++;
			j--;
		}
	}			//	TEST 2 //
	
	else if (n == 2)
	{
		while(tet2[i] != 0)
		{
			if (tet2[i] == '\n')
				i++;
			if (tet2[i] == '#')
			{
			//	tetrimino = set_bit(tetrimino, j);
			}
			i++;
			j--;
		}
	}			//	TEST 3	//
	else if (n == 3)
	{
		while(tet3[i] != 0)
		{
			if (tet3[i] == '\n')
				i++;
			if (tet3[i] == '#')
			{
			//	tetrimino = set_bit(tetrimino, j);
			}
			i++;
			j--;
		}
	}			//	TEST 4	//
	else if (n == 4)
	{
		while(tet4[i] != 0)
		{
			if (tet4[i] == '\n')
				i++;
			if (tet4[i] == '#')
		//		tetrimino = set_bit(tetrimino, j);
			i++;
			j--;
		}
	}			//	TEST 5	//
	else if (n == 5)
	{
		while(tet5[i] != 0)
		{
			if (tet5[i] == '\n')
				i++;
			if (tet5[i] == '#')
			{
				printf("i: %d, j: %d\n", i, j);
			//	tetrimino = set_bit(tetrimino, j);
			}
			i++;
			j--;
		}
	}
	//shift_tetrimino(tetrimino);
	//tetrimino = tetrimino << 48;
	//printf("%llu\n", tetrimino);
	//bin(tetrimino);

	
	unsigned long long test = 0;
	test = (1ULL << 63) | test;
	printf("\nthe most relevant bit in 64 bits is %llu\n", test);
	bin(test);
	*/

	return 0;
}
