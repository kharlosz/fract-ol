/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:27:29 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 05:02:18 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_itoa3(int n)
{
	int		j;
	int		n2;

	j = 0;
	if (n == 0)
		j++;
	if (n < 0)
	{
		j++;
		n2 = -n;
	}
	else
		n2 = n;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		j++;
	}
	return (j);
}

char			*ft_itoa(int n)
{
	int		j;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (ft_itoa3(n) + 1));
	if (str)
	{
		j = ft_itoa3(n);
		if (n < 0)
			n = -n;
		str[j] = '\0';
		j--;
		while (n > 0)
		{
			str[j] = n % 10 + 48;
			n = n / 10;
			j--;
		}
		if (j == 0)
			str[0] = '-';
	}
	return (str);
}
