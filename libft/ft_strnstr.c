/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:53:50 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 01:02:04 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	j = 0;
	l = ft_strlen(s2);
	if (s1[0] == '\0' && s2[0] == '\0')
		return ("");
	while (i + j < n && i < ft_strlen(s1))
	{
		while (s1[i + j] == s2[j] && j < l)
			j++;
		if (j == l && i + j <= n)
			return ((char *)s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
