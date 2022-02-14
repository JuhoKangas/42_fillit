/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:15 by amajer            #+#    #+#             */
/*   Updated: 2022/02/11 17:23:48 by amajer           ###   ########.fr       */
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

void	ft_validate_file(char *buff, int pieces)
{
	int	i;
			//index buffer
	i = 0;
	printf("pieces : %i\n", pieces);
	printf("tetrimino: %s\n", buff);
	if (pieces > 0)
	{
		while(buff[i] != 0)
		{
			if (buff[i] == '\n')
				i++;
			else if (i % 5 == 0 && buff[i] != '\n')
			{
				printf("newline error end of line char: %c, at index: %i", buff[i], i);
				error(0);
			}
			else 
			{
				if (buff[i] != '.' && buff[i] != '#')
				{
					printf("wrong character 1");
					printf("\n|%c| at the index of %d", buff[i], i);
					error(0);
				}
			}
			i++;
		}
	}
	else
	{
		while(buff[i] != 0)
		{
			if ((i + 1) % 5 == 0)
			{
				if (buff[i] != '\n')
				{
					printf("newline error end of line char: %c, at index: %i", buff[i], i);
					error(0);
				}
			}
			else if (buff[i] != '.' && buff[i] != '#')
			{
				printf("wrong character 2");
				printf("\n|%c| at the index of %d", buff[i], i);
				error(0);
			}
			i++;
		}
	}	
}

/*
void 	ft_validate_file(char *buff)
{
	int	i;
	int	j;
	pieces = 1;

	j = 0;
	i = 0;
	while(buff[i] != 0)
	{
		if (i % 20 == 0)
			j++;
		if ((i + j) % 21 == 0)
		{
			if (buff[i] != '\n')
				{
				printf("newline error at the end of file");
				error(0);
				}
		}
		else if ((i + j) % 5 == 0)
		{
			if (buff[i] != '\n')
				{
					printf("newline error end of line char: %c, at index: %i", buff[i], i);
					error(0);
				}
		}
		else
		{
			if (buff[i] != '.' && buff[i] != '#')
				{
					printf("wrong character");
					printf("\n%c at the index of %d", buff[i], i);
					error(0);
				}
		}
		i++;
	}
}
*/

