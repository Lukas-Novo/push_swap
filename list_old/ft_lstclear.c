/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:35:06 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/19 19:28:16 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OK

#include "push_swap.h"

// clear the list from the given node till the end.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		ft_lstdelone(temp, del);
	}
}
