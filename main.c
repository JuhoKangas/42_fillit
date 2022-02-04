/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:40:42 by amajer            #+#    #+#             */
/*   Updated: 2022/02/04 17:58:14 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sorry wrote so little my gf not feeling good, i think she has flu :(  )

#include <fcntl.h>

int ft_validate_file(char *buff)
{

}

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*buff[546];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(0);
	ret = read(fd, buff, 546);
	if (ret < 0)
		error(0);
	ft_validate_file(buff);


	if (argc != 2)
		error(1);
	
}