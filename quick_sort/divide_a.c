/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:12:56 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 19:28:09 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	divide_a(t_list **a_stack, t_list **b_stack, unsigned int a_min,
			unsigned int a_max)
{
	unsigned int	pivot;
	unsigned int	count_back;
	unsigned int	size;

	size = a_max - a_min + 1;
	if (size == 2)
	{
		sa(a_stack);
		return ;
	}
	if (size == 3)
	{
		sort_a_top_three(a_stack);
		return ;
	}
	pivot = find_pivot(a_min, a_max);
	count_back = divide_a_with_pivot(a_stack, b_stack, pivot, a_min);
	shortest_rotations(a_stack, count_back, ra, rra);
	if (check_order(a_stack, pivot, a_max, 1) < 1)
		divide_a(a_stack, b_stack, pivot, a_max);
	divide_b(a_stack, b_stack, a_min, pivot);
}

unsigned int	divide_a_with_pivot(t_list **a_stack, t_list **b_stack,
					unsigned int pivot, unsigned int a_min)
{
	unsigned int	count_back;
	unsigned int	count;

	count_back = 0;
	count = a_min;
	while (count < pivot)
	{
		if ((*a_stack)->converted < pivot)
		{
			pb(a_stack, b_stack);
			++count;
		}
		else
		{
			ra(a_stack);
			++count_back;
		}
	}
	return (count_back);
}
