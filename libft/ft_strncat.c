/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:13:06 by jkangas           #+#    #+#             */
/*   Updated: 2021/11/24 17:17:31 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len > n)
	{
		ft_memcpy(&s1[s1_len], s2, n);
		s1[s1_len + n] = '\0';
	}
	else
	{
		ft_memcpy(&s1[s1_len], s2, s2_len);
		s1[s1_len + s2_len] = '\0';
	}
	return (s1);
}
