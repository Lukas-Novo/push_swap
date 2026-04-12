/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:06:34 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/18 19:11:50 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OK

#include "push_swap.h"

// Returns the last node of the list.

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
