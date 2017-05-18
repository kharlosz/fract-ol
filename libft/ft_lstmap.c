/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:06:58 by carodrig          #+#    #+#             */
/*   Updated: 2016/01/04 11:17:31 by carodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*temp;
	t_list	*temp2;

	lst2 = NULL;
	if (lst && f)
	{
		lst2 = f(lst);
		temp = lst2;
		while (lst->next)
		{
			lst = lst->next;
			temp2 = f(lst);
			if (!temp2)
				return (0);
			temp->next = temp2;
			temp = temp->next;
		}
	}
	return (lst2);
}
