#include "push_swap.h"

void	merge_sort(t_list **a_stack, t_list **b_stack)
{

}

void	divide_b(t_list **a_stack, t_list **b_stack, unsigned int b_min, unsigned int b_max);

void	divide_a(t_list **a_stack, t_list **b_stack, unsigned int a_min, unsigned int a_max)
{
	unsigned int	pivot;
	unsigned int	count;
	unsigned int	count_back;

	pivot = (a_min + a_max) / 2;
	count =  a_max;
	count_back = 0;

	while (count > pivot)
	{
		if ((*a_stack)->converted <= pivot && (*a_stack)->converted >= a_min)
		{
			pb(a_stack, b_stack);
			--count;
		}
		else
		{
			ra(a_stack);
			++count_back;
		}	
	}
	while (count_back > 0)
	{
		rra(a_stack);
		--count_back;
	}
	// checker if stack a is already orderer
	divide_a(a_stack, b_stack, pivot, a_max);
	divide_b(a_stack, b_stack, a_min, pivot);
}