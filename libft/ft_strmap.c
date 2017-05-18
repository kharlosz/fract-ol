/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:29:23 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 01:47:00 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	s2 = NULL;
	if (f && s)
	{
		while (s[i])
			i++;
		s2 = (char *)malloc(sizeof(char) * (i + 1));
		if (s2)
		{
			i = 0;
			while (s[i])
			{
				s2[i] = f(s[i]);
				i++;
			}
			s2[i] = '\0';
		}
	}
	return (s2);
}
