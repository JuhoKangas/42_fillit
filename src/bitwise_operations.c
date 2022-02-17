/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:58:40 by amajer            #+#    #+#             */
/*   Updated: 2022/02/16 14:24:25 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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