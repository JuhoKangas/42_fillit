/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/07 16:30:13 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

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
	if (ft_validate_file(buff) == 0)
		return (0);

	return (0);	
}