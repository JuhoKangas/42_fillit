/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkangas <jkangas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:45:47 by jkangas           #+#    #+#             */
/*   Updated: 2021/12/08 19:47:46 by jkangas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_power(int base, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res *= base;
		power--;
	}
	return (res);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_setnbr(char *str, int len, int n)
{
	int	i;
	int	div;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		len--;
	}
	while (len > 0)
	{
		div = ft_power(10, len - 1);
		str[i] = ft_abs(n / div) + 48;
		n %= div;
		i++;
		len--;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_setnbr(str, len, n);
	return (str);
}
