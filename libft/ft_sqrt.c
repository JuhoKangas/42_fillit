/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:20:45 by jkangas           #+#    #+#             */
/*   Updated: 2022/03/02 13:24:36 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int num)
{
	long int	start;
	long int	end;
	long int	mid;

	start = 0;
	end = num;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == num)
			return (mid);
		else if (mid * mid < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}
