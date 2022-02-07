/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:06:06 by amajer            #+#    #+#             */
/*   Updated: 2021/12/07 16:51:25 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	diff;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	while (s1[i] == s2[i] && (int)n > 1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
		n--;
	}
	diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (diff);
}
