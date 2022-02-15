/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:15 by amajer            #+#    #+#             */
/*   Updated: 2022/02/15 18:17:51 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void error(int i)
{
	if (i == 1)
		exit(1);
	// {
	// 	ft_putstr("usage:\n");
	// }
	else if (i == 0)
		exit(1);
	// {
	// 	ft_putstr("error\n");
	// }

}

int ft_validate_piece(char *piece)
{
	int	i;
	int	contacts;

	i = 0;
	contacts = 0;
	while(piece[i] != 0)
	{
		if (piece[i] == '#')
		{
			if (i > 0)
				if (piece[i - 1] == '#')
					contacts++;
			if (i < 19)
				if (piece[i + 1] == '#')
					contacts++;
			if (i > 4)
				if (piece[i - 5] == '#')
					contacts++;
			if (i < 15)
				if (piece[i + 5] == '#')
					contacts++;
		}
		i++;
	}
	printf("this tetrimino has %i contact points.\n", contacts);
	return (contacts == 6 || contacts == 8);
}

void	ft_validate_file(char *buff, int pieces)
{
	int	i;
	int	blocks;
	int	positions[5];

	i = 0;
	blocks = 0;
	printf("piece number : %i\n", pieces);
	printf("tetrimino:\n\n%s", buff);
	if (pieces > 26)
	{
		printf("too many pieces\n");
		error(0);
	}
	if (buff[20] != '\n' && buff[20] != '\0')
	{
		printf("invalid file\n");
		error(0);
	}
	while(i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n' && i > 1)
		{
			printf("newline error at end of line, char: '%c', at index: %i", buff[i], i);
			error(0);
		}
		if ((i + 1) % 5 != 0)
		{
			if (buff[i] != '.' && buff[i] != '#')
			{
				printf("|%c| at the index of %d", buff[i], i);
				error(0);
			}
		}
		if (buff[i] == '#' && ++blocks > 4)
		{
			printf("block number check\n");
			error(0);
		}
		i++;
	}
	if (!ft_validate_piece(buff))
	{
		printf("error at validate piece.\n");
		error(0);
	}
	ft_measure_piece(buff, positions, -1);
}
