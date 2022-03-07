/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:59:31 by jkangas           #+#    #+#             */
/*   Updated: 2022/03/07 17:28:27 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*init_map(int size)
{
	char	*str;
	int		x;
	int		y;

	str = ft_strnew((size + 1) * size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			str[y * (size + 1) + x] = '.';
			x++;
		}
		str[y * (size + 1) + x] = '\n';
		y++;
	}
	return (str);
}

void	print_map(t_etrimino *tet, int pieces, int size)
{
	char	*str;
	int		x;
	int		y;

	str = init_map(size);
	while (pieces > 0)
	{
		y = 0;
		while (y < tet->height)
		{
			x = 0;
			while (x < tet->width)
			{
				if ((tet->value >> (16 * (y + 1) - 1 - x)) & 1)
					str[(tet->y + y) * (size + 1) + x + tet->x] = tet->id;
				x++;
			}
			y++;
		}
		tet++;
		pieces--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}
