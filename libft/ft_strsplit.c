/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 17:00:45 by carodrig          #+#    #+#             */
/*   Updated: 2016/02/17 12:16:13 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_strsplit2(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
			{
				while (s[i] == c)
					i++;
			}
			else
			{
				j++;
				while (s[i] != c && s[i])
					i++;
			}
		}
		return (j);
	}
	return (-1);
}

static char		**ft_strsplit3(int j2, char **t, char const *s, char c)
{
	int i2;
	int j;
	int i;

	i = 0;
	j = 0;
	i2 = 0;
	while (j < j2)
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			i2 = i;
			while (s[i] != c && s[i])
				i++;
			t[j] = ft_strsub(s, i2, i - i2);
			j++;
		}
	}
	t[j] = NULL;
	return (t);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**t;

	i = 0;
	j = ft_strsplit2(s, c);
	t = (char **)malloc(sizeof(char *) * (j + 1));
	if (t)
		return (ft_strsplit3(j, t, s, c));
	return (NULL);
}
