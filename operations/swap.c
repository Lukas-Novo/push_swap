/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:12:59 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 20:37:41 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *stack;
	if (first == NULL || first == first->next)
		return ;
	if ((*stack)->prev == (*stack)->next)
	{
		rotate(stack);
		return ;
	}
	last = first->prev;
	second = first->next;
	third = second->next;
	last->next = second;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	*stack = second;
}

void	sa(t_list **a_stack)
{
	swap(a_stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **b_stack)
{
	swap(b_stack);
	write(1, "sb\n", 3);
}

// void	ss(t_list **a_stack, t_list **b_stack)
// {
// 	swap(a_stack);
// 	swap(b_stack);
// 	write(1, "ss\n", 3);
// }
