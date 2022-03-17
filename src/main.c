/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/03/17 16:45:03 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			pieces;
	t_etrimino	tetris[MAX_TETRI + 1];
	int			size;

	if (argc != 2)
		return (error("usage: ./fillit [input_file]"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error("error"));
	ft_bzero(tetris, sizeof(*tetris) * (MAX_TETRI + 1));
	pieces = ft_reader_function(fd, tetris);
	size = solve_map(tetris, pieces);
	print_map(tetris, pieces, size);
	if (close(fd) != 0)
		return (error("error"));
	return (0);
}
