/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:44:05 by carodrig          #+#    #+#             */
/*   Updated: 2015/12/22 16:37:21 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		while (s[j])
			j++;
		while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || !s[j]))
			j--;
		if (j > 0)
			return (ft_strsub(s, i, j + 1 - i));
	}
	s2 = (char *)malloc(sizeof(char));
	s2[0] = '\0';
	return (s2);
}
