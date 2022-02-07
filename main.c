/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/07 16:40:09 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

/*
int ft_validate_file(char *buff)
{
	return (0);
}
*/

void	ft_print_block(int fd)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
}

void error(int i)
{
	if (i == 1)
	{
		printf("error 1");
	}
	else if (i == 0)
	{
		printf("error 0");
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*buff[BUFF_SIZE + 1];

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(0);
	ret = read(fd, buff, BUFF_SIZE);
	if (close(fd) != 0)
		error(0);
	buff[ret] = '0';
	if (ret < 0)
		error(0);
//	ft_validate_file(buff);
	ft_print_block(fd);

	if (argc != 2)
		error(1);
	
}
