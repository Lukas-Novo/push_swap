/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_top_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:12:44 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 19:34:09 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_list **a_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (first->converted > third->converted
		&& first->converted > second->converted)
		ra(a_stack);
	else if (second->converted > first->converted
		&& second->converted > third->converted)
		rra(a_stack);
	first = *a_stack;
	second = first->next;
	if (first->converted > second->converted)
		sa(a_stack);
}

void	sort_a_top_three(t_list **a_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (third->next == first)
		sort_three(a_stack);
	else if (first->converted > third->converted
		&& first->converted > second->converted)
		sort_a_top_three_first_biggest(a_stack, second, third);
	else if (second->converted > first->converted
		&& second->converted > third->converted)
		sort_a_top_three_second_biggest(a_stack, first, third);
	else
		sort_a_top_three_third_biggest(a_stack, first, second);
}

void	sort_a_top_three_first_biggest(t_list **a_stack, t_list *second,
			t_list *third)
{
	sa(a_stack);
	ra(a_stack);
	sa(a_stack);
	rra(a_stack);
	if (second->converted > third->converted)
		sa(a_stack);
}

void	sort_a_top_three_second_biggest(t_list **a_stack, t_list *first,
			t_list *third)
{
	ra(a_stack);
	sa(a_stack);
	rra(a_stack);
	if (first->converted > third->converted)
		sa(a_stack);
}

void	sort_a_top_three_third_biggest(t_list **a_stack, t_list *first,
			t_list *second)
{
	if (first->converted > second->converted)
		sa(a_stack);
}
