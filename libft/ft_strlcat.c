/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:04:44 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/08 16:16:29 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (i < dstsize - dst_len - 1 && src[i] != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i != 0)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
