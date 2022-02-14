/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/11 17:25:33 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** Utility function to get min-max values for get_piece.
** pos is a 4 dimensional array encoded as: xMin 0, xMax 1, yMin 2, yMax 3
*/
void	ft_measure_piece(char *str, int *positions)
{
	int	i;
	int	tetris_width;
	int	tetris_height;

	i = 0;
	positions[0] = 3;
	positions[1] = 0;
	positions[2] = 3;
	positions[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < positions[0])
				positions[0] = i % 5;
			if (i % 5 > positions[1])
				positions[1] = i % 5;
			if (i / 5 < positions[2])
				positions[2] = i / 5;
			if (i / 5 > positions[3])
				positions[3] = i / 5;
		}
		i++;
	}
	tetris_width = positions[1] - positions[0] + 1;
	tetris_height = positions[3] - positions[2] + 1;


	ft_putstr("tetris_width is : ");
	ft_putnbr(tetris_width);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("tetris_height is : ");
	ft_putnbr(tetris_height);
	ft_putchar('\n');
}

/*
void	ft_print_block(int fd)
{
	char *line;


	while (get_next_line(fd, &line) == 1)
	{	
		ft_putendl(line);
		ft_putstr(line);
		ft_strdel(&line);
	}
}
*/

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff[21];
	int		pieces;
	int		positions[5];

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	pieces = 0;
	while(ret > 0)
	{
		ret = read(fd, buff, 20);
		if (fd < 0 || ret <= 0)
			error(0);
		buff[ret] = '\0';
		ft_validate_file(buff, pieces);
		ft_measure_piece(buff, positions);
		pieces = pieces + 1;
	}
	if (close(fd) != 0)
		error(1);
	return(0);
}
