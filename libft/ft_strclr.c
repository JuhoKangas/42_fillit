/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:00:17 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/02 16:53:11 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	s_len;
	size_t	i;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		s[i] = '\0';
		i++;
	}
}
