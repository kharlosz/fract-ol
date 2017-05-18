/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:32:57 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/04 13:19:43 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src2;
	size_t	dst2;
	int		i;
	int		j;
	int		k;

	dst2 = ft_strlen(dst);
	src2 = ft_strlen(src);
	j = 0;
	k = size - dst2 - 1;
	i = dst2;
	while (src[j] && j < k)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (size <= dst2)
		return (src2 + size);
	return (src2 + dst2);
}
