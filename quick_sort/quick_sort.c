/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:12:48 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 19:31:26 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	unsigned int	size;

	size = stack_size(a_stack);
	if (check_order_stack_a(a_stack) == 1)
		return ;
	divide_a(a_stack, b_stack, 1, size);
}

void	shortest_rotations(t_list **stack, unsigned int count_back,
			void (*r)(t_list **), void (*rr)(t_list **))
{
	unsigned int	size;

	size = stack_size(stack);
	if (size - count_back > count_back)
	{
		while (count_back > 0)
		{
			rr(stack);
			--count_back;
		}
	}
	else
	{
		count_back = size - count_back;
		while (count_back > 0)
		{
			r(stack);
			--count_back;
		}
	}
}

unsigned int	find_pivot(unsigned int min, unsigned int max)
{
	unsigned int	pivot;

	pivot = (min + max);
	if (pivot % 2 == 0)
		pivot = pivot / 2;
	else
		pivot = pivot / 2 + 1;
	return (pivot);
}
