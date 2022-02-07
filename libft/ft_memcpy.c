/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:10:14 by amajer            #+#    #+#             */
/*   Updated: 2021/12/03 13:36:52 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = (int)(-1);
	if (!(dst) && !(src))
		return (dst);
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}
