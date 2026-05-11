/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:13:35 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 17:13:36 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_list **stack)
{
	t_list	*head;

	if (stack == NULL || *stack == NULL)
		return ;
	head = (*stack)->prev;
	(*stack)->prev = NULL;
	while (head->prev != NULL)
	{
		head = head->prev;
		free(head->next);
	}
	free(head);
	*stack = NULL;
}
