#include "push_swap.h"

float	check_order(t_list **stack)
{
	t_list *head;
	unsigned int	total;
	unsigned int	ordered;

	head = *stack;
	total = 0;
	ordered = 0;
	if (head == NULL)
		return 1;
	if (head == head->next)
		return 1;
	// if (head->converted < (head->next)->converted)
	// 	++ordered;
	// ++total;
	// head = head->next;
	while (head->next != *stack)
	{
		if (head->converted < (head->next)->converted)
			++ordered;
		++total;
		head = head->next;
	}
	return ((float) ordered / total);
}