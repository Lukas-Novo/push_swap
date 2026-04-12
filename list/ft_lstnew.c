/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:08:22 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/18 18:43:49 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OK

#include "push_swap.h"

// Create new list.

t_list	*ft_lstnew(int original, t_list *a_stack)
{
	t_list	*new;
	t_list	*pars;

	pars = a_stack;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->original = original;
	new->converted = 1;
	new->prev = new;
	new->next = new;
	if (a_stack == NULL)
		return (new);
	new->next = a_stack;
	new->prev = a_stack->prev;
	(new->next)->prev = new;
	(new->prev)->next = new;
	while (pars != new)
	{
		if (new->original > pars->original)
			new->converted += 1;
		else if (new->original < pars->original)
			pars->converted += 1;
		else
			return (NULL);
		pars = pars->next;
	}
	return (new);
}
