/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/16 14:25:37 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(0);
	ft_reader_function(fd, 1);
	if (close(fd) != 0)
		error(1);
	return (0);
}
