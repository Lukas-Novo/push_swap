#include "push_swap.h"

void	stack_clear(t_list **stack)
{
	t_list	*head;

	if (*stack == NULL)
		return ;
	head = (*stack)->prev;
	while (head != *stack)
	{
		head = head->prev;
		free(head->next);
	}
	free(head);
	*stack = NULL;
}
