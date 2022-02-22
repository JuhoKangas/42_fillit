/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:14:53 by amajer            #+#    #+#             */
/*   Updated: 2022/02/22 15:18:41 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void bin(unsigned long long n);

unsigned long long set_bit(unsigned long long tetrimino, int index)
{
	int	posix;
	int	posiy;
	
	posix = index % 5;
	posiy = index / 5;
//	printf("\nx is %i, y is %i.\n", posix, posiy);
	tetrimino = (1L << (16 * (posiy + 1) - 1 - posix)) | tetrimino;
	return (tetrimino);
}

void	left_shift(unsigned long long tetrimino)
{
	int	i;

	i = 3;
	printf("\nbefore left shift\n");
	bin(tetrimino);
	printf("\n");
	while (i-- > 0)
		if (!(tetrimino & 1ULL << 15) && !(tetrimino & 1ULL << 14) && !(tetrimino & 1ULL << 13) && !(tetrimino & 1ULL << 12))
			tetrimino = tetrimino >> 16;
	bin(tetrimino);
}

int	main()
{
	char tetrimino2[21] = "....\n..##\n...#\n...#\n";
	char tetrimino3[21] = "....\n.#..\n###.\n....\n";
	char tetrimino4[21] = "....\n.###\n..#.\n....\n";
	char tetrimino5[21] = "....\n####\n....\n....\n";

	unsigned long long tetrimino = 0;
	int i = 0;

			// TEST NUMBER	//
	int n = 2;

	if (n == 2)
	{
		while(tetrimino2[i] != 0)
		{
			if (tetrimino2[i] == '\n')
				i++;
			if (tetrimino2[i] == '#')
			{
				printf("num %d\n", i);
				tetrimino = set_bit(tetrimino, i);
			}
			i++;
		}
		left_shift(tetrimino);
	}
	
	
				//	TEST 3	//
	else if (n == 3)
	{
		while(tetrimino3[i] != 0)
		{
			if (tetrimino3[i] == '\n')
				i++;
			if (tetrimino3[i] == '#')
			{
				tetrimino = set_bit(tetrimino, i);
			}
			i++;

		}
	}			//	TEST 4	//
	else if (n == 4)
	{
		while(tetrimino4[i] != 0)
		{
			if (tetrimino4[i] == '\n')
				i++;
			if (tetrimino4[i] == '#')
				tetrimino = set_bit(tetrimino, i);
			i++;

		}
	}			//	TEST 5	//
	else if (n == 5)
	{
		while(tetrimino5[i] != 0)
		{
			if (tetrimino5[i] == '\n')
				i++;
			if (tetrimino5[i] == '#')
			{
				tetrimino = set_bit(tetrimino, i);
			}
			i++;

		}
	}
	//shift_tetrimino(tetrimino);
	//tetrimino = tetrimino << 30;

	/*
	unsigned long long test = 0;
	test = (1ULL << 63) | test;
	printf("\nthe most relevant bit in 64 bits is %llu\n", test);
	bin(test);
	*/

	return 0;
}

// void bin(unsigned long long n)
// {
// 	int i = 64;

// 	while (i--)
// 	{
// 		if (n  & (1ULL << i))
// 			printf("1 ");
// 		else 
// 			printf("0 ");
// 		if (i % 16 == 0 && i != 0) // change modulo to 8 for 8x8 map or 16 for 16x4 map 
// 			printf("\n");
// 	}
// 	printf("\n");
// }

// unsigned long long set_bit(unsigned long long tetrimino, int index)
// {
// 	// int	posix;
// 	// int	posiy;
	
// 	// posix = index / 5;
// 	// posiy = index % 5;
// 	tetrimino = (1L << index) | tetrimino;
// 	return (tetrimino);
// }

// void	ft_array_to_integer(char **tetrimino_array)
// {
// 	int					i;
// 	int					j;
// 	unsigned long long	tetrimino;

// 	i = 0;
// 	j = 0;
// 	tetrimino = 0;
// 	while (tetrimino_array[j][0] != '\0')
// 	{
// 		if (tetrimino_array[j][0] == '#')
// 			tetrimino = set_bit(tetrimino, 4);
// 		if (tetrimino_array[j][1] == '#')
// 			tetrimino = set_bit(tetrimino, 3);
// 		if (tetrimino_array[j][2] == '#')
// 			tetrimino = set_bit(tetrimino, 2);
// 		if (tetrimino_array[j][3] == '#')
// 			tetrimino = set_bit(tetrimino, 1);
// 		if (j < 3)
// 			tetrimino = tetrimino << 16;
// 		j++;
// 	}
// 	bin(tetrimino);
// }

// char	**allocate_array()
// {
// 	char	**array;
// 	int		i;

// 	i = 0;
// 	array = (char **)malloc(sizeof(char *) * 5);
// 	if (array == NULL)
// 		error(0);
// 	while (i < 4)
// 	{
// 		array[i] = (char *)malloc(sizeof(char) * 5);
// 		if (array[i] == NULL)
// 		{
// 			while (i > -1)
// 			{
// 				ft_strdel(&array[i]);
// 				i--;
// 			}
// 			free(array);
// 			array = NULL;
// 			error(0);
// 		}
// 		i++;
// 	}
// 	return (array);
// }

// void	ft_string_to_array(char *str, int i, int j, int z)
// {
// 	char	**array;

// 	array = allocate_array();
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\n')
// 		{
// 			array[j][z] = '\0';
// 			j++;
// 			z = 0;
// 			i++;
// 		}
// 		else
// 		{
// 			array[j][z] = str[i];
// 			i++;
// 			z++;
// 		}
// 	}
// 	printf("lalalalalal\n");
// 	array[4][0] = '\0';
// 	printf("buhubuhu\n");
// 	ft_array_to_integer(array);
// }
