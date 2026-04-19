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

void	rr(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
