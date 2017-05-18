/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 05:38:27 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 06:32:02 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	x;

	i = 0;
	j = 0;
	x = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		x = str[i];
		str[i] = str[j];
		str[j] = x;
		i++;
		j--;
	}
	return (str);
}