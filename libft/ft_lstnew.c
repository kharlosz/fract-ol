/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:24:40 by carodrig          #+#    #+#             */
/*   Updated: 2016/02/17 11:10:22 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		if (content)
		{
			lst->content = (void *)malloc(sizeof(char) * content_size);
			if (lst->content)
			{
				ft_memcpy(lst->content, content, content_size);
				lst->content_size = content_size;
			}
			else
				lst->content_size = 0;
		}
		else
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		lst->next = NULL;
	}
	return (lst);
}
