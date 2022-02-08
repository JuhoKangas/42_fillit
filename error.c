/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:15 by amajer            #+#    #+#             */
/*   Updated: 2022/02/08 15:57:29 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void error(int i)
{
	if (i == 1)
	{
		ft_putstr("usage:\n");
	}
	else if (i == 0)
	{
		ft_putstr("error\n");
	}
	exit(1);
}

void 	ft_validate_file(char *buff)
{
	int	i;

	i = 0;
	while(buff[i] != 0)
	{
		if ((i + 1) % 21 == 0)
		{
			if (buff[i] != '\n')
				error(0);
		}
		else if ((i + 1) % 5 == 0)
		{
			if (buff[i] != '\n')
				error(0);
		}
		else
		{
			if (buff[i] != '.' || buff[i] != '#')
				error(0);
		}
		i++;
	}
}