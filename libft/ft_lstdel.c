/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:58:18 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/04 11:10:36 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*temp;

	if (*alst && del)
	{
		lst = *alst;
		while (lst)
		{
			temp = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = temp;
		}
		*alst = NULL;
	}
}
