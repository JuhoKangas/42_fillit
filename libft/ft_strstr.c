/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:54:31 by amajer            #+#    #+#             */
/*   Updated: 2021/12/03 13:13:07 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	z;
	int	i;
	int	y;

	i = 0;
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char *)needle);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		y = 0;
		z = i;
		while (haystack[i + y] == needle[y])
		{
			if (needle [y + 1] == '\0')
				return (&((char *)haystack)[z]);
			y++;
		}
		i++;
	}
	return (NULL);
}
