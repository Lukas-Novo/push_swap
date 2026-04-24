#include "push_swap.h"

void	insertion_sort(t_list **a_stack, t_list **b_stack)
{
	unsigned int	max;
	unsigned int	i;

	max = stack_size(a_stack);
	i = 1;
	while (i <= max)
	{
		while ((*a_stack)->converted != i)
		{
			ra(a_stack);
		}
		pb(a_stack, b_stack);
		++i;
	}
	while (*b_stack != NULL)
	{
		pa(b_stack, a_stack);
	}
}