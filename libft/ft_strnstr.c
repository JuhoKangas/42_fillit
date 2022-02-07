/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:07:55 by amajer            #+#    #+#             */
/*   Updated: 2021/12/03 13:25:22 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	z;
	size_t	i;
	size_t	y;

	i = 0;
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		y = 0;
		z = i;
		while (haystack[i + y] == needle[y] && (i + y) < len)
		{
			if (needle [y + 1] == '\0')
				return (&((char *)haystack)[z]);
			y++;
		}
		i++;
	}
	return (NULL);
}
