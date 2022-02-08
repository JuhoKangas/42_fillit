/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/08 12:05:39 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_block(int fd)
{
	char *line;


	while (get_next_line(fd, &line) == 1)
	{	
		ft_putstr("do we get here?");
		ft_putendl(line);
		ft_putstr(line);
		ft_strdel(&line);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff[456 + 1];
	int		pieces;

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buff, 456 + 1);
	ft_putnbr(ret);
	ft_putchar('\n');
	if (fd < 0 || ret <= 0)
		error(0);
	if (((ret + 1) % 21) != 0)
		error(0);
	pieces = (ret + 1) / 21;
	buff[ret] = '\0';
	if (close(fd) != 0)
		ft_putstr("error(2)\n");
	ft_validate_file(buff, ret);
	
	return(0);
}
