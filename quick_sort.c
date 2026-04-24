#include "push_swap.h"

void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	unsigned int	size;

	size = stack_size(a_stack);
	if (size == 3)
		sort_three(a_stack);
	if (check_order(a_stack, 1, size, 1) == 1)
		return ;
	divide_a(a_stack, b_stack, 1, size);
}

void	sort_three(t_list **a_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (first->converted > third->converted && first->converted > second->converted)
		ra(a_stack);
	else if(second->converted > first->converted && second->converted > third->converted)
		rra(a_stack);
	first = *a_stack;
	second = first->next;
	if (first->converted > second->converted)
		sa(a_stack);
}

void	shortest_rotations(t_list **stack, unsigned int count_back, void (*r)(t_list **), void (*rr)(t_list **))
{
	unsigned int	size;

	size = stack_size(stack);
	if (size - count_back > count_back)
	{
		while (count_back > 0)
		{
			rr(stack);
			--count_back;
		}
	}
	else
	{
		count_back = size - count_back;
		while (count_back > 0)
		{
			r(stack);
			--count_back;
		}
	}
}

void	pa_block(t_list **a_stack, t_list **b_stack, unsigned int b_min, unsigned int b_max)
{
	unsigned int	count;
	unsigned int	size;

	size = b_max - b_min + 1;
	count = 0;
	while (count < size)
	{
		pa(b_stack, a_stack);
		++count;
	}
	
}

void	divide_b(t_list **a_stack, t_list **b_stack, unsigned int b_min, unsigned int b_max)
{
	unsigned int	pivot;
	unsigned int	count;
	unsigned int	count_back;

	if (b_min == b_max)
		return ;
	--b_max;
	pivot = (b_min + b_max);
	if (pivot % 2 == 0)
		pivot = pivot / 2;
	else
		pivot = pivot / 2 + 1;
	count =  b_max;
	count_back = 0;
	if (check_order(b_stack, 1, 0, 0) == 1)
	{
		pa_block(a_stack, b_stack, b_min, b_max);
		return ;
	}
	if (b_max - b_min == 1)
	{
		if ((*b_stack)->converted < (*b_stack)->next->converted)
			sb(b_stack);
		pa(b_stack, a_stack);
		pa(b_stack, a_stack);
		return ;
	}
	while (count >= pivot)
	{
		if ((*b_stack)->converted >= pivot)
		{
			pa(b_stack, a_stack);
			--count;
		}
		else
		{
			rb(b_stack);
			++count_back;
		}	
	}
	shortest_rotations(b_stack, count_back, rb, rrb);
	if (check_order(a_stack, pivot, b_max, 1) < 1)
		divide_a(a_stack, b_stack, pivot, b_max);
	divide_b(a_stack, b_stack, b_min, pivot);
}

void	divide_a(t_list **a_stack, t_list **b_stack, unsigned int a_min, unsigned int a_max)
{
	unsigned int	pivot;
	unsigned int	count;
	unsigned int	count_back;

	pivot = (a_min + a_max);
	if (pivot % 2 == 0)
		pivot = pivot / 2;
	else
		pivot = pivot / 2 + 1;
	count =  a_min;
	count_back = 0;

// zde algoritmus pro vyřešení dvou nebo tří čísel
	if (a_max - a_min == 1)
	{
		sa(a_stack);
		return ;
	}
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
	shortest_rotations(a_stack, count_back, ra, rra);
	if (check_order(a_stack, pivot, a_max, 1) < 1)
		divide_a(a_stack, b_stack, pivot, a_max);
	divide_b(a_stack, b_stack, a_min, pivot);
}