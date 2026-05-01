#include "push_swap.h"

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