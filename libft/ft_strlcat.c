/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:09:46 by amajer            #+#    #+#             */
/*   Updated: 2021/12/13 17:07:21 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = dst_len;
	j = 0;
	if (dstsize < dst_len)
		return (ft_strlen(src) + dstsize);
	while (src[j] != '\0' && i < (dstsize - 1))
		dst[i++] = src[j++];
	while (src[j] != 0)
		j++;
	dst[i] = '\0';
	return (j + dst_len);
}
