/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:52:40 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/08 15:40:53 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t_new;

	t_new = (t_list *)malloc(sizeof(*t_new));
	if (t_new == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		t_new->content = NULL;
		t_new->content_size = 0;
	}
	else
	{
		t_new->content = (void *)malloc(content_size);
		if (t_new->content == NULL)
		{
			free(t_new);
			return (NULL);
		}
		ft_memcpy(t_new->content, content, content_size);
		t_new->content_size = content_size;
	}
	t_new->next = NULL;
	return (t_new);
}
