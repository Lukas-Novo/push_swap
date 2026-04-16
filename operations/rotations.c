#include "push_swap.h"

void	rotate(t_list **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	write(1, "--- rotate ---\n", 15);
}

void	rev_rotate(t_list **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	rev_rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}