/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:54:24 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 01:48:09 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (n > 0)
	{
		if (i < ft_strlen(src))
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
		n--;
	}
	return (dst);
}
