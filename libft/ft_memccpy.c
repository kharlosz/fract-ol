/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:56:44 by carodrig          #+#    #+#             */
/*   Updated: 2015/12/22 19:07:54 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	i = 0;
	src2 = (char *)src;
	dst2 = (char *)dst;
	while (i < n)
	{
		if (src2[i])
			dst2[i] = src2[i];
		if (src2[i] == c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
