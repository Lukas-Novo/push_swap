/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:57:53 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/18 19:06:39 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OK

#include "push_swap.h"

// Counts the number of nodes in the list.

unsigned int	stack_size(t_list *stack)
{
	unsigned int	count;
	t_list	*head;

	if (stack == NULL)
		return (0);
	head = stack;
	count = 1;
	head = head->next;
	while (head != stack)
	{
		count++;
		head = head->next;
	}
	return (count);
}
