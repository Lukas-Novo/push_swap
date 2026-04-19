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

void	rrr(t_list **a_stack, t_list **b_stack)
{
	rev_rotate(a_stack);
	rev_rotate(b_stack);
	write(1, "rrr\n", 4);
}