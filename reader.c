/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:22 by amajer            #+#    #+#             */
/*   Updated: 2022/02/15 18:53:44 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_reader_function(int fd, int ret)
{
	int		previous_ret;
	char	buff[22];
	int		pieces;

	pieces = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, 21);
		printf("ret is :%i\n", ret);
		if (ret > 0)
		{
			if ((fd < 0 || ret < 0) || (pieces == 0 && ret == 0))
			{
				printf("fd < 0 || ret < 0\n");
				error(0);
			}
			buff[ret] = '\0';
			ft_validate_file(buff, pieces);
			pieces++;
			previous_ret = ret;
		}
	}
	if (previous_ret != 20)
	{
		printf("file ends wrong\n");
		error(0);
	}
}