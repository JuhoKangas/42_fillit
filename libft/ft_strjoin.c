/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:41:41 by amajer            #+#    #+#             */
/*   Updated: 2021/12/07 13:30:44 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_join(char const *s1, char const *s2, char *new_str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strnew(0));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_join(s1, s2, new_str);
	return (new_str);
}
