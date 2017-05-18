/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 06:51:21 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/05 07:09:53 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int i;
	int j;

	i = 0;
	j = 7;
	while (i < 8)
	{
		ft_putnbr(octet / ft_recursive_power(2, j));
		octet = octet % ft_recursive_power(2, j);
		i++;
		j--;
	}
}
