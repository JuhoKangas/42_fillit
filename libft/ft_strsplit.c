/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:44:59 by amajer            #+#    #+#             */
/*   Updated: 2021/12/13 16:46:15 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_populate(const char *s, char **str, char c)
{
	int	i;
	int	a;
	int	j;

	j = 0;
	i = 0;
	a = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			str[a][j] = ((char *)s)[i];
			j++;
			i++;
		}
		a++;
		j = 0;
	}
	return (str);
}

static int	ft_measure(const char *s, char c)
{
	int	count;
	int	i;
	int	word;

	count = 0;
	i = 0;
	word = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			word++;
			if (word == 1)
				count++;
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_measure(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < ft_measure(s, c))
	{
		str[i] = ft_strnew(ft_strlen(s));
		if (!str[i])
		{
			while (i >= 0)
				free(str[i--]);
			return (NULL);
			free(str);
		}
		i++;
	}
	str[i] = NULL;
	return (ft_populate(s, str, c));
}
