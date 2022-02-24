/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:22 by amajer            #+#    #+#             */
/*   Updated: 2022/02/24 16:03:48 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_reader_function(int fd)
{
	int		previous_ret;
	char	buff[22];
	int		pieces;
	int		ret;

	pieces = 1;
	ret = read(fd, buff, 21);
	while (ret > 0)
	{
		printf("\n____________________________\nret is :%i\n", ret);
		buff[ret] = '\0';
		ft_validate_file(buff, pieces);
		pieces++;
		previous_ret = ret;
		ret = read(fd, buff, 21);
	}
	if (previous_ret != 20 || ret < 0)
	{	
		printf("file ends wrong or read failed\n");
		error(0);
	}
}