/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:21:36 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/10 19:13:13 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	end;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	end = ft_strlen(s);
	while ((ft_isspace(s[end]) || s[end] == '\0') && end != i)
		end--;
	ret = ft_strsub(s, i, end - i + 1);
	return (ret);
}
