/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:43:22 by amajer            #+#    #+#             */
/*   Updated: 2022/02/25 18:00:27 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_etrimino build_piece(int piece_index, char *buff)
{
	t_etrimino tetrimino;
	int i;
	char piece_id;

	i = -1;
	piece_id = 'A' - 1;
	while (++i <= piece_index)
		piece_id++;
	tetrimino.value = ft_string_to_ull(buff);
	tetrimino.width = ft_measure_width(buff);
	tetrimino.height = ft_measure_height(buff);
	tetrimino.id = piece_id;
	return (tetrimino);
}

int	ft_reader_function(int fd, t_etrimino *tetris)
{
	int		previous_ret;
	char	buff[21];
	int		piece_index;
	int		ret;


	piece_index = 0;
	ret = read(fd, buff, 21);

	while (ret > 0)
	{
		buff[ret] = '\0';
		if (ft_validate_file(buff, piece_index) == 1)
			error(0);
		tetris[piece_index] = build_piece(piece_index, buff);
		previous_ret = ret;
		ret = read(fd, buff, 21);
		piece_index++;
	}
	if (previous_ret != 20 || ret < 0)
		error(0);
	return (piece_index);
}
