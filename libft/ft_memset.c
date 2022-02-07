/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:35:11 by amajer            #+#    #+#             */
/*   Updated: 2021/12/06 17:24:07 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	my_char;
	unsigned char	*temp;
	size_t			i;

	i = (int)(-1);
	my_char = (unsigned char)c;
	temp = b;
	while (++i < len)
		temp[i] = my_char;
	return (b);
}
