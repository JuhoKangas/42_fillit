/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:32 by amajer            #+#    #+#             */
/*   Updated: 2022/02/25 16:56:04 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int ft_validate_shape(char *piece_index)
{
	int	contacts;
	int	i;

	i = 0;
	contacts = 0;
	while(piece_index[i] != '\0')
	{
		if (piece_index[i] == '#')
		{
			if (i > 0)
				if (piece_index[i - 1] == '#')
					contacts++;
			if (i < 19)
				if (piece_index[i + 1] == '#')
					contacts++;
			if (i > 4)
				if (piece_index[i - 5] == '#')
					contacts++;
			if (i < 15)
				if (piece_index[i + 5] == '#')
					contacts++;
		}
		i++;
	}
	// printf("this tetrimino has %i contact points.\n", contacts);
	// return (contacts == 6 || contacts == 8);
	return (contacts);
}

int	ft_validate_file(char *buff, int piece_index)
{
	int	i;
	int	blocks;

	i = 0;
	blocks = 0;
	if ((piece_index > 26) || (buff[20] != '\n' && buff[20] != '\0'))
		error(0);
	while(i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n' && i > 1)
			return(1);
		if ((i + 1) % 5 != 0)
			if (buff[i] != '.' && buff[i] != '#')
				return(1);
		if (buff[i] == '#' && ++blocks > 4)
			return(1);
		i++;
	}
	if (ft_validate_shape(buff) != 6 && ft_validate_shape(buff) != 8)
		return(1);
	return (0);
}
