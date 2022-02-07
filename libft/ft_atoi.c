/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:27 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/08 18:25:14 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_LLONG_MAX 9223372036854775807

static int	ft_parse_numstr(const char *str, int base, int sign)
{
	long long	res;
	long long	cutoff;
	int			cutlim;

	cutoff = FT_LLONG_MAX;
	cutlim = cutoff % base + '0';
	cutoff /= base;
	res = 0;
	while (ft_isdigit(*str))
	{
		if (res > cutoff || (res == cutoff && *str > cutlim))
		{
			res = 0 - (sign > 0);
			break ;
		}
		res = res * 10 + *str++ - '0';
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int		return_value;
	int		sign;

	sign = 1;
	return_value = 0;
	if (*str == '\0')
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = 1 - 2 * (*str++ == '-');
	return_value = ft_parse_numstr(str, 10, sign);
	return (sign * return_value);
}
