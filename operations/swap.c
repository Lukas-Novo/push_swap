#include "push_swap.h"

void	swap(t_list *first)
{
	t_list	*last;
	t_list	*second;
	t_list	*third;

	if (first == NULL || first == first->next)
		return ;
	last = first->prev;
	second = first->next;
	third = second->next;
	last->next = second;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
}