/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:38:16 by lnovotny          #+#    #+#             */
/*   Updated: 2026/03/28 17:41:55 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				original;
	unsigned int	converted;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int				error();
t_list			*check_input(int argc, char *argv[]);
int				ft_atoi(const char *str);
char			*check_atoi(char *str);

t_list			*stack_a_alloc(int original, t_list *a_stack);
void			stack_clear(t_list **stack);
unsigned int	stack_size(t_list *stack);
void			swap(t_list **first);
void			sa(t_list **a_stack);
void			sb(t_list **b_stack);
void			ss(t_list **a_stack, t_list **b_stack);
static void		relink_from(t_list **from, t_list *last, t_list *second);
static void		relink_to(t_list **to, t_list *last, t_list *first, t_list *new);
void			push(t_list **from, t_list **to);
void			pa(t_list **b_stack, t_list **a_stack);
void			pb(t_list **a_stack, t_list **b_stack);
void			rotate(t_list **stack);
void			ra(t_list **a_stack);
void			rb(t_list **b_stack);
void			rr(t_list **a_stack, t_list **b_stack);
void			rev_rotate(t_list **stack);
void			rra(t_list **a_stack);
void			rrb(t_list **b_stack);
void			rrr(t_list **a_stack, t_list **b_stack);

void	insertion_sort(t_list **a_stack, t_list **b_stack);

void	print_stack(t_list *stack);
#endif
