/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:59:25 by amajer            #+#    #+#             */
/*   Updated: 2022/02/22 14:59:49 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void bin(unsigned long long n)
{
	int i = 15;
	while (i > -1)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");
					//second line
	i = 31;
	while (i > 15)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
			i--;
	}
	printf("\n");
					//third line
	i = 47;
	while (i > 31)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");
					//fourth line
	i = 63;
	while (i > 47)
	{
		if (n  & (1ULL << i))
			printf("1 ");
		else 
			printf("0 ");
		i--;
	}
	printf("\n");

}