/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:27:15 by amajer            #+#    #+#             */
/*   Updated: 2022/02/07 16:29:13 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_validate_file(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while(i < BUFF_SIZE)
	{
		j = 0;
		while ((buff[j] == '#' || buff[j] == '\n' || buff[j] == '.') && j <= 20)
		{
			j++;
			i++;
		}
		if (buff[i] != '\n')
		{
			 error(0);
			return (0);
		}
	}
	return (0);
}