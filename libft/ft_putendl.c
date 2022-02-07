/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:16:54 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/02 17:00:08 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
	ft_putchar('\n');
}
