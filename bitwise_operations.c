/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:58:40 by amajer            #+#    #+#             */
/*   Updated: 2022/02/08 15:23:40 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	set_bit(unsigned short tet, int posix)
{
	tet = ((1 << posix) | tet);
	return (tet);
}


/*
	need structure for this
*/
unsigned short	shift_tet_top_left(unsigned short tet)
{
	  
}