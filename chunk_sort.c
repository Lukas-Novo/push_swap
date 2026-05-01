#include "push_swap.h"

long	find_in_chunk(t_list **stack, unsigned int value)
{
	t_list 			*stack_value;
	long			position;
	unsigned int	size;

	stack_value = *stack;
	position = 0;
	size = stack_size(stack);
	while (stack_value->converted != value)
	{
		stack_value = stack_value->next;
		++position;
	}
	if (position > size - position)
		return (position - size);
	return (position);
}

long	distance_from_zero(long position)
{
	if (position >= 0)
		return (position);
	else
		return (-position);
}

void	sort_chunk_to_a(t_list **a_stack, t_list **b_stack)
{
	long	position_big;
	long	position_small;
	unsigned int	max;

	max = stack_size(b_stack);
	while (*b_stack && max > 0)
	{
		position_big = find_in_chunk(b_stack, max);
		// --chunk_size;
		--max;
		if (max > 0)
		{
			position_small = find_in_chunk(b_stack, max);
			if (distance_from_zero(position_big) <= distance_from_zero(position_small))
			{
				while (position_big != 0)
				{
					if (position_big > 0)
					{
						rb(b_stack);
						--position_big;
					}
					else
					{
						rrb(b_stack);
						++position_big;
					}
				}
				pa(a_stack, b_stack);
			}
			else
			{
				while (position_small != 0)
				{
					if (position_small > 0)
					{
						rb(b_stack);
						--position_small;
					}
					else
					{
						rrb(b_stack);
						++position_small;
					}
				}
				pa(a_stack, b_stack);
				position_big = find_in_chunk(b_stack, max + 1);
				while (position_big != 0)
				{
					if (position_big > 0)
					{
						rb(b_stack);
						--position_big;
					}
					else
					{
						rrb(b_stack);
						++position_big;
					}
				}
				pa(a_stack, b_stack);
				if ((*a_stack)->converted > (*a_stack)->next->converted)
					sa(a_stack);
				// --chunk_size;
				--max;
			}
		}
		else
		{
			while (position_big != 0)
			{
				if (position_big > 0)
				{
					rb(b_stack);
					--position_big;
				}
				else
				{
					rrb(b_stack);
					++position_big;
				}
			}
			pa(a_stack, b_stack);
		}
	}
}

void	chunk_sort(t_list **a_stack, t_list **b_stack)
{
	int		chunk_size;
	int		count;
	long	max;
	long	min;

	chunk_size = 18;
	count = chunk_size;
	max = chunk_size;
	min = 0;
	while (*a_stack)
	{
		if ((*a_stack)->converted > min && (*a_stack)->converted <= max)
		{
			pb(a_stack, b_stack);
			if ((*b_stack)->converted <= min + chunk_size / 2)
				rb(b_stack);
			--count;
			if (count < 1)
			{
				max = max + chunk_size;
				min = min + chunk_size;
				count = chunk_size;
			}
		}
		else
			ra(a_stack);
	}
	sort_chunk_to_a(a_stack, b_stack);
}
