#include <push_swap.h>

void	sort_b_top_three(t_list **a_stack, t_list **b_stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *b_stack;
	second = first->next;
	third = second->next;
	if (first->converted > third->converted && first->converted > second->converted)
		sort_b_top_three_first_biggest(a_stack, b_stack, second, third);
	else if(second->converted > first->converted && second->converted > third->converted)
		sort_b_top_three_second_biggest(a_stack, b_stack, first, third);
	else
		sort_b_top_three_third_biggest(a_stack, b_stack, first, second);
}

void	sort_b_top_three_first_biggest(t_list **a_stack, t_list **b_stack, t_list *second, t_list *third)
{
	pa(a_stack, b_stack);
		if (second->converted < third->converted)
			sb(b_stack);
		pa(a_stack, b_stack);
		pa(a_stack, b_stack);
}

void	sort_b_top_three_second_biggest(t_list **a_stack, t_list **b_stack, t_list *first, t_list *third)
{
	sb(b_stack);
	pa(a_stack, b_stack);
	if (third->converted > first->converted)
		sb(b_stack);
	pa(a_stack, b_stack);
	pa(a_stack, b_stack);
}

void	sort_b_top_three_third_biggest(t_list **a_stack, t_list **b_stack, t_list *first, t_list *second)
{
	if(second->converted > first->converted)
		sb(b_stack);
	pa(a_stack, b_stack);
	sb(b_stack);
	pa(a_stack, b_stack);
	sa(a_stack);
	pa(a_stack, b_stack);
}


