/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:33:17 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/09 17:39:30 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_add_str(char const *s, char c)
{
	size_t	len;
	char	*str;

	len = ft_wordlen(s, c);
	str = ft_strsub(s, 0, len);
	return (str);
}

static char	**ft_free_split(char **arr, int size)
{
	while (size > 0)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	word_count;

	if (s == 0)
		return (NULL);
	word_count = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(*split) * word_count + 1);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		split[i] = ft_add_str(s, c);
		if (split[i] == NULL)
			return (ft_free_split(split, i - 1));
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
