/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:13:31 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 18:31:12 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	stack_size(t_list **stack)
{
	unsigned int	count;
	t_list			*head;

	if (*stack == NULL)
		return (0);
	head = *stack;
	count = 1;
	head = head->next;
	while (head != *stack)
	{
		count++;
		head = head->next;
	}
	return (count);
}
