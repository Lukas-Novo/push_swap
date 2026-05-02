#include <push_swap.h>

void	sort_three(t_list **a_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (first->converted > third->converted && first->converted > second->converted)
		ra(a_stack);
	else if(second->converted > first->converted && second->converted > third->converted)
		rra(a_stack);
	first = *a_stack;
	second = first->next;
	if (first->converted > second->converted)
		sa(a_stack);
}

void	sort_a_top_three_cases(t_list **a_stack, t_list *first, t_list *second, t_list *third)
{
	if (first->converted > third->converted && first->converted > second->converted)
	{
		sa(a_stack);
		ra(a_stack);
		sa(a_stack);
		rra(a_stack);
		if (second->converted > third->converted)
			sa(a_stack);
	}
	else if(second->converted > first->converted && second->converted > third->converted)
	{
		ra(a_stack);
		sa(a_stack);
		rra(a_stack);
		if (first->converted > third->converted)
			sa(a_stack);
	}
	else
	{
		if(first->converted > second->converted)
			sa(a_stack);
	}
}

void	sort_a_top_three(t_list **a_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_stack;
	second = first->next;
	third = second->next;
	if (third->next == first)
		sort_three(a_stack);
	else
		sort_a_top_three_cases(a_stack, first, second, third);
}


