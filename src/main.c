/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/03/02 13:02:35 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			pieces;
	t_etrimino	tetris[26];
	int			i;

	i = 0;
	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(0);
	pieces = ft_reader_function(fd, tetris);
	printf("number of pieces is: %i.\n", pieces);
	while (i < pieces)
	{
		printf("\n\npiece number: %i\n", i);
		printf("\nID: %c\n", tetris[i].id);
		bin(tetris[i].value);
		printf("\npiece width: %i", tetris[i].width);
		printf("\npiece height: %i", tetris[i].height);

		i++;
	}
	if (close(fd) != 0)
		error(1);
	return (0);
}
