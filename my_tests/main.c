/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:14:53 by amajer            #+#    #+#             */
/*   Updated: 2022/02/11 14:52:36 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define I_0 0b1111000000000000UL
# define I_1 0b1000100010001000UL
# define J_0 0b1110001000000000UL
# define J_1 0b0100010011000000UL
# define J_2 0b1000111000000000UL
# define J_3 0b1100100010000000UL
# define L_0 0b1110100000000000UL
# define L_1 0b1100010001000000UL
# define L_2 0b0010111000000000UL
# define L_3 0b1000100011000000UL
# define O_0 0b1100110000000000UL
# define S_0 0b0110110000000000UL
# define S_1 0b1000110001000000UL
# define T_0 0b1110010000000000UL
# define T_1 0b0100110001000000UL
# define T_2 0b0100111000000000UL
# define T_3 0b1000110010000000UL
# define Z_0 0b1100011000000000UL
# define Z_1 0b0100110010000000UL


/*
unsigned long long shift_tetrimino(unsigned long long tetrimino)
{

}
*/
void bin(unsigned long long n)
{
	int i = 64;

	while (i--)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		if (i % 16 == 0 && i != 0) // change modulo to 8 for 8x8 map or 16 for 16x4 map 
			printf("\n");
	}
}

unsigned long long set_bit(unsigned long long tet, int index)
{
	int	posix;
	int	posiy;
	
	posix = index / 5;
	posiy = index % 5;
	tet = (1L << (16 * (posiy + 1) - posix - 1)) | tet;
	return (tet);
}

int	main()
{
	char tet1[21] = "...#\n...#\n...#\n...#\n";
	char tet2[21] = "....\n..##\n...#\n...#\n";
	char tet3[21] = "....\n.#..\n###.\n....\n";
	char tet4[21] = "....\n.###\n..#.\n....\n";
	char tet5[21] = "....\n####\n....\n....\n";

	unsigned long long tetrimino = 0;
	int i = 0;
	int j = 21;

			// TEST NUMBER	//
	int n = 2;
	
			//	TEST 1	//
	if (n == 1)
	{
		while(tet1[i] != 0)
		{
			if (tet1[i] == '\n')
				i++;
			if (tet1[i] == '#')
			{
					tetrimino = set_bit(tetrimino, j);
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
				tetrimino = set_bit(tetrimino, j);
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
				tetrimino = set_bit(tetrimino, j);
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
				tetrimino = set_bit(tetrimino, j);
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
				tetrimino = set_bit(tetrimino, j);
			}
			i++;
			j--;
		}
	}
	//shift_tetrimino(tetrimino);
	//tetrimino = tetrimino << 30;
	printf("%llu\n", tetrimino);
	bin(tetrimino);

	/*
	unsigned long long test = 0;
	test = (1ULL << 63) | test;
	printf("\nthe most relevant bit in 64 bits is %llu\n", test);
	bin(test);
	*/

	return 0;
}
