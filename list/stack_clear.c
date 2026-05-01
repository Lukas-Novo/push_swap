#include "push_swap.h"

void	stack_clear(t_list **stack)
{
	t_list	*head;

	if (stack == NULL || *stack == NULL)
		return ;
	head = (*stack)->prev;
	(*stack)->prev = NULL;
	while (head->prev != NULL)
	{
		head = head->prev;
		free(head->next);
	}
	free(head);
	*stack = NULL;
}
