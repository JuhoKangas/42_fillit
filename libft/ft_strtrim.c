/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:57:46 by amajer            #+#    #+#             */
/*   Updated: 2021/12/13 13:56:38 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calculate_len(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[len] != 0)
		len++;
	len--;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len -= i;
	return (len);
}

char	*ft_strtrim(char const *s)
{
	size_t		j;
	size_t		i;
	size_t		len;
	char		*copy;

	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	len = ft_calculate_len(s);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	while (len > 0)
	{
		copy[j++] = s[i++];
		len--;
	}
	copy[j++] = s[i];
	copy[j] = '\0';
	return (copy);
}
