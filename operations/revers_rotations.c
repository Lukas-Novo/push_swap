/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:13:05 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 20:37:30 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_list **a_stack)
{
	rev_rotate(a_stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b_stack)
{
	rev_rotate(b_stack);
	write(1, "rrb\n", 4);
}

// void	rrr(t_list **a_stack, t_list **b_stack)
// {
// 	rev_rotate(a_stack);
// 	rev_rotate(b_stack);
// 	write(1, "rrr\n", 4);
// }
