/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/15 18:25:24 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** Utility function to get min-max values for get_piece.
** pos is a 4 dimensional array encoded as: xMin 0, xMax 1, yMin 2, yMax 3
*/
void	ft_measure_piece(char *str, int *positions, int i)
{
	int	tetris_width;
	int	tetris_height;

	positions[0] = 3;
	positions[1] = 0;
	positions[2] = 3;
	positions[3] = 0;
	while (++i < 20)
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
	}
	tetris_width = positions[1] - positions[0] + 1;
	tetris_height = positions[3] - positions[2] + 1;
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		previous_ret;
	char	buff[22];
	int		pieces;

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	pieces = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, 21);
		printf("ret is :%i\n", ret);
		if (ret > 0)
		{
			if (fd < 0 || ret < 0)
			{
				printf("fd < 0 || ret < 0\n");
				error(0);
			}
			if (pieces == 0 && ret == 0)
			{
				printf("empty file\n");
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
	if (close(fd) != 0)
		error(1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		previous_ret;
	char	buff[22];
	int		pieces;

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	pieces = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, 21);
		if (ret > 0)
		{
			if ((fd < 0 || ret < 0) || (pieces == 0 && ret == 0))
				error(0);
			buff[ret] = '\0';
			ft_validate_file(buff, pieces);
			pieces++;
			previous_ret = ret;
		}
	}
	if (previous_ret != 20)
		error(0);
	if (close(fd) != 0)
		error(1);
	return (0);
}