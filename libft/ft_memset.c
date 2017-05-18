/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:47:30 by carodrig          #+#    #+#             */
/*   Updated: 2015/12/22 15:13:55 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b2;
	size_t	i;

	b2 = (char *)b;
	i = 0;
	while (i < len)
	{
		b2[i] = c;
		i++;
	}
	return ((void *)b2);
}