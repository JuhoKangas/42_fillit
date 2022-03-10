/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:32 by amajer            #+#    #+#             */
/*   Updated: 2022/03/08 16:38:27 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 * Validates the tetrimino shape. All the correct solutions have either
 * 6 or 8 sides touching. Returns the number of the sides touching.
 */

int	ft_validate_shape(char *piece_index)
{
	int	contacts;
	int	i;

	i = 0;
	contacts = 0;
	while (piece_index[i] != '\0')
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
	return (contacts);
}

/*
 * Checks the correct input from the file. Returns 1 if error occurs in
 * validation, otherwise return 0.
 */

int	ft_validate_file(char *buff, int piece_index)
{
	int	i;
	int	blocks;

	i = 0;
	blocks = 0;
	if ((piece_index > 26) || (buff[20] != '\n' && buff[20] != '\0'))
		return (error("error"));
	while (i < 20)
	{
		if ((i + 1) % 5 == 0 && buff[i] != '\n' && i > 1)
			return (1);
		if ((i + 1) % 5 != 0)
			if (buff[i] != '.' && buff[i] != '#')
				return (1);
		if (buff[i] == '#' && ++blocks > 4)
			return (1);
		i++;
	}
	if (ft_validate_shape(buff) != 6 && ft_validate_shape(buff) != 8)
		return (1);
	return (0);
}
