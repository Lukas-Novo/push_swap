#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *stack)
{
    t_list  *head;

	printf("STACK SIZE: %u\n", stack_size(stack));
    head = stack;
	printf("%d\t| %u\n", head->original, head->converted);
	head = head->next;
	while (head != stack)
	{
		printf("%d\t| %u\n", head->original, head->converted);
		head = head->next;
	}
}

