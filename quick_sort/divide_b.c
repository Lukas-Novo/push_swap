/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:12:52 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 19:28:37 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	divide_b(t_list **a_stack, t_list **b_stack, unsigned int b_min,
			unsigned int b_max)
{
	unsigned int	pivot;
	unsigned int	count_back;
	unsigned int	size;

	if (b_min == b_max)
		return ;
	--b_max;
	size = b_max - b_min + 1;
	if (size == 2)
	{
		sort_b_two(a_stack, b_stack);
		return ;
	}
	if (size == 3)
	{
		sort_b_top_three(a_stack, b_stack);
		return ;
	}
	pivot = find_pivot(b_min, b_max);
	count_back = divide_b_with_pivot(a_stack, b_stack, pivot, b_max);
	shortest_rotations(b_stack, count_back, rb, rrb);
	if (check_order(a_stack, pivot, b_max, 1) < 1)
		divide_a(a_stack, b_stack, pivot, b_max);
	divide_b(a_stack, b_stack, b_min, pivot);
}

unsigned int	divide_b_with_pivot(t_list **a_stack, t_list **b_stack,
					unsigned int pivot, unsigned int b_max)
{
	unsigned int	count_back;
	unsigned int	count;

	count_back = 0;
	count = b_max;
	while (count >= pivot)
	{
		if ((*b_stack)->converted >= pivot)
		{
			pa(a_stack, b_stack);
			--count;
		}
		else
		{
			rb(b_stack);
			++count_back;
		}
	}
	return (count_back);
}

void	sort_b_two(t_list **a_stack, t_list **b_stack)
{
	if ((*b_stack)->converted < (*b_stack)->next->converted)
		sb(b_stack);
	pa(a_stack, b_stack);
	pa(a_stack, b_stack);
}
