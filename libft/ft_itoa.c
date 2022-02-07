/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:08:28 by amajer            #+#    #+#             */
/*   Updated: 2021/12/13 18:22:53 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_populate_str(char *str, int len, int n)
{
	int	sign;

	sign = (n < 0);
	if (sign)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len] = '\0';
	while (n > 9)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	str[--len] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	return (ft_populate_str(str, len, n));
}
