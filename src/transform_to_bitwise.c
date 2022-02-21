/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_bitwise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:12:35 by amajer            #+#    #+#             */
/*   Updated: 2022/02/21 18:34:24 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	printf("\n");
}

unsigned long long set_bit(unsigned long long tet, int index)
{
	// int	posix;
	// int	posiy;
	
	// posix = index / 5;
	// posiy = index % 5;
	tet = (1L << index) | tet;
	return (tet);
}

void	ft_array_to_integer(char **tetrimino_array)
{
	int					i;
	int					j;
	unsigned long long	tet;

	i = 0;
	j = 0;
	tet = 0;
	while (tetrimino_array[j][0] != '\0')
	{
		if (tetrimino_array[j][0] == '#')
			tet = set_bit(tet, 4);
		if (tetrimino_array[j][1] == '#')
			tet = set_bit(tet, 3);
		if (tetrimino_array[j][2] == '#')
			tet = set_bit(tet, 2);
		if (tetrimino_array[j][3] == '#')
			tet = set_bit(tet, 1);
		if (j < 3)
			tet = tet << 16;
		j++;
	}
	bin(tet);
}

char	**allocate_array()
{
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * 5);
	if (array == NULL)
		error(0);
	while (i < 4)
	{
		array[i] = (char *)malloc(sizeof(char) * 5);
		if (array[i] == NULL)
		{
			while (i > -1)
			{
				ft_strdel(&array[i]);
				i--;
			}
			free(array);
			array = NULL;
			error(0);
		}
		i++;
	}
	return (array);
}

void	ft_string_to_array(char *str, int i, int j, int z)
{
	char	**array;

	array = allocate_array();
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			array[j][z] = '\0';
			j++;
			z = 0;
			i++;
		}
		else
		{
			array[j][z] = str[i];
			i++;
			z++;
		}
	}
	printf("lalalalalal\n");
	array[4][0] = '\0';
	printf("buhubuhu\n");
	ft_array_to_integer(array);
}
