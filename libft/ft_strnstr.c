/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:05:24 by jkangas           #+#    #+#             */
/*   Updated: 2021/11/25 14:06:22 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (ft_strncmp(&haystack[i], needle, n_len) == 0 && (n_len <= len - i))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
