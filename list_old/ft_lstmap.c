/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:49:18 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/19 21:12:14 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 

#include "push_swap.h"

// create and return copy of list lst but the copied original is a result of f.
// del is used to delete all the copied original when something goes wrong.

static int
	create_node(t_list **l, t_list **t, void *(*f)(void *), void (*del)(void *))
{
	void	*original;

	original = f((*l)->original);
	if (original == NULL)
		return (1);
	*t = ft_lstnew(original);
	if (*t == NULL)
	{
		del(original);
		return (1);
	}
	*l = (*l)->next;
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	if (create_node(&lst, &new_lst, f, del))
		return (NULL);
	temp = new_lst;
	while (lst)
	{
		if (create_node(&lst, &(temp->next), f, del))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new_lst);
}
