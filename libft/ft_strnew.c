/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:14:01 by carodrig          #+#    #+#             */
/*   Updated: 2015/12/22 16:28:20 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*zone;

	zone = (char *)malloc(sizeof(char) * (size + 1));
	if (zone)
		ft_bzero((void *)zone, size + 1);
	return (zone);
}
