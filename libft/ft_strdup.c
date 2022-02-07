/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:00:40 by jkangas           #+#    #+#             */
/*   Updated: 2021/11/08 16:41:48 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*rt_str;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	rt_str = (char *)malloc(sizeof(char) * len + 1);
	if (!rt_str)
		return (NULL);
	while (s1[i])
	{
		rt_str[i] = s1[i];
		i++;
	}
	rt_str[i] = '\0';
	return (rt_str);
}
