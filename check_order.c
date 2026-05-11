/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:06:24 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 19:27:38 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	check_order(t_list **stack, unsigned int min, unsigned int max,
			int ascending)
{
	t_list			*head;
	unsigned int	count;
	unsigned int	ordered;
	unsigned int	size;

	head = *stack;
	count = 0;
	ordered = 0;
	if (max == 0)
		max = stack_size(stack);
	size = max - min;
	if (head == NULL || head == head->next || size == 0)
		return (1);
	while (head->next != *stack && count < size)
	{
		if (head->converted < (head->next)->converted)
			++ordered;
		++count;
		head = head->next;
	}
	if (ascending)
		return ((float) ordered / count);
	return (1 - (float) ordered / count);
}

float	check_order_stack_a(t_list **stack)
{
	return (check_order(stack, 1, 0, 1));
}
