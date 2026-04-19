#include "push_swap.h"


static void	relink_from(t_list **from, t_list *last, t_list *second)
{
	if (last == last->next)
	{
		*from = NULL;
		return ;
	}
	last->next = second;
	second->prev = last;
	*from = second;
}

static void	relink_to(t_list **to, t_list *last, t_list *first, t_list *new)
{
	*to = new;
	if (first == NULL)
	{
		new->prev = new;
		new->next = new;
		return ;
	}
	last->next = new;
	new->prev = last;
	new->next = first;
	first->prev = new;
}

void	push(t_list **from, t_list **to)
{
	t_list	*last_from;
	t_list	*first_from;
	t_list	*second_from;
	t_list	*last_to;
	t_list	*first_to;

	first_from = *from;
	first_to = *to;
	if (first_from == NULL)
		return ;
	last_from = first_from->prev;
	second_from = first_from->next;
	last_to = NULL;
	if (first_to != NULL)
		last_to = first_to->prev;
	relink_from(from, last_from, second_from);
	relink_to(to, last_to, first_to, first_from);
}

void	pa(t_list **b_stack, t_list **a_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	pb(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
