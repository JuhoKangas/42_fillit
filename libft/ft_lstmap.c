/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:51 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/08 15:40:38 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	free_new(t_list **new)
{
	free((*new)->content);
	free(*new);
	*new = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f);
		if (new->next == NULL)
			free_new(&new);
	}
	return (new);
}
