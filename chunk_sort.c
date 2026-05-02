#include "push_swap.h"

void	chunk_sort(t_list **a_stack, t_list **b_stack)
{
	int		chunk_size;

	chunk_size = 18;
	move_chunks_to_b(a_stack, b_stack, chunk_size);
	sort_chunks_to_a(a_stack, b_stack);
}

void	move_chunks_to_b(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int		count;
	long	max;

	count = chunk_size;
	max = chunk_size;
	while (*a_stack)
	{
		if ((*a_stack)->converted <= max)
		{
			pb(a_stack, b_stack);
			if ((*b_stack)->converted <= max - chunk_size / 2)
				rb(b_stack);
			--count;
			if (count < 1)
			{
				max = max + chunk_size;
				count = chunk_size;
			}
		}
		else
			ra(a_stack);
	}
}

void	sort_chunks_to_a(t_list **a_stack, t_list **b_stack)
{
	long			position_big;
	long			position_small;
	unsigned int	max;

	max = stack_size(b_stack);
	while (*b_stack && max > 0)
	{
		position_big = find_position_in_chunk(b_stack, max);
		--max;
		position_small = find_position_in_chunk(b_stack, max);
		if (max == 0 || distance_from_zero(position_big) <= distance_from_zero(position_small))
			find_in_b_push_to_a(a_stack, b_stack, position_big);
		else
		{
			find_in_b_push_to_a(a_stack, b_stack, position_small);
			position_big = find_position_in_chunk(b_stack, max + 1);
			find_in_b_push_to_a(a_stack, b_stack, position_big);
			if ((*a_stack)->converted > (*a_stack)->next->converted)
				sa(a_stack);
			--max;
		}
	}
}

void	find_in_b_push_to_a(t_list **a_stack, t_list **b_stack, long position)
{
	while (position != 0)
	{
		if (position > 0)
		{
			rb(b_stack);
			--position;
		}
		else
		{
			rrb(b_stack);
			++position;
		}
	}
	pa(a_stack, b_stack);
}

long	find_position_in_chunk(t_list **stack, unsigned int value)
{
	t_list 			*stack_value;
	long			position;
	unsigned int	size;

	if (value == 0)
		return (0);
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