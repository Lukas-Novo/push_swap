/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:13:03 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 20:37:35 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_list **a_stack)
{
	rotate(a_stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **b_stack)
{
	rotate(b_stack);
	write(1, "rb\n", 3);
}

// void	rr(t_list **a_stack, t_list **b_stack)
// {
// 	rotate(a_stack);
// 	rotate(b_stack);
// 	write(1, "rr\n", 3);
// }
