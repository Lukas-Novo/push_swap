#include "push_swap.h"

void	quick_sort(t_list **a_stack, t_list **b_stack)
{
	unsigned int	size;

	size = stack_size(a_stack);
	if (check_order(a_stack, 1, size, 1) == 1)
		return ;
	divide_a(a_stack, b_stack, 1, size);
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

unsigned int	find_pivot(unsigned int min, unsigned int max)
{
	unsigned int	pivot;

	pivot = (min + max);
	if (pivot % 2 == 0)
		pivot = pivot / 2;
	else
		pivot = pivot / 2 + 1;
	return (pivot);
}

float	check_order(t_list **stack, unsigned int min, unsigned int max, int ascending)
{
	t_list *head;
	unsigned int	count;
	unsigned int	ordered;
	unsigned int	size;

	head = *stack;
	count = 0;
	ordered = 0;
	if (max == 0)
		max = stack_size(stack);
	size = max - min;
	if (head == NULL || head == head->next || size == 0)
		return 1;
	while (head->next != *stack && count < size)
	{
		if (head->converted < (head->next)->converted)
			++ordered;
		++count;
		head = head->next;
	}
	if (ascending)
		return ((float) ordered / count);
	return (1 - (float) ordered / count);
}
