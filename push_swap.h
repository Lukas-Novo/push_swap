/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:38:16 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 20:37:59 by lnovotny         ###   ########.fr       */
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

t_list			*add_to_stack(char *arg, t_list **a_stack);
int				check_size(char *str, int size_num);
int				check_overflow(char *str, int original);
t_list			*create_node(int original);
t_list			*connect_node(t_list **stack, t_list *new);
void			stack_clear(t_list **stack);
unsigned int	stack_size(t_list **stack);

void			relink_from(t_list **from, t_list *last, t_list *second);
void			relink_to(t_list **to, t_list *last, t_list *first,
					t_list *new);
void			push(t_list **from, t_list **to);
void			pa(t_list **a_stack, t_list **b_stack);
void			pb(t_list **a_stack, t_list **b_stack);

void			rotate(t_list **stack);
void			ra(t_list **a_stack);
void			rb(t_list **b_stack);
// void			rr(t_list **a_stack, t_list **b_stack);

void			rev_rotate(t_list **stack);
void			rra(t_list **a_stack);
void			rrb(t_list **b_stack);
// void			rrr(t_list **a_stack, t_list **b_stack);

void			swap(t_list **first);
void			sa(t_list **a_stack);
void			sb(t_list **b_stack);
// void			ss(t_list **a_stack, t_list **b_stack);

void			chunk_sort(t_list **a_stack, t_list **b_stack);
void			move_chunks_to_b(t_list **a_stack, t_list **b_stack,
					int chunk_size);
void			sort_chunks_to_a(t_list **a_stack, t_list **b_stack);
void			find_in_b_push_to_a(t_list **a_stack, t_list **b_stack,
					long position);
long			find_position_in_chunk(t_list **stack, unsigned int value);

int				ft_atoi(char *str);
int				skip_whitespace_and_sign(char *str, int *sign);

t_list			*initialize_stack(char *argv[]);
char			*check_and_add_number(char *str_next, t_list **head);
char			*check_atoi(char *str);
int				is_cifer(char num);

void			sort_b_top_three(t_list **a_stack, t_list **b_stack);
void			sort_b_top_three_first_biggest(t_list **a_stack,
					t_list **b_stack, t_list *second, t_list *third);
void			sort_b_top_three_second_biggest(t_list **a_stack,
					t_list **b_stack, t_list *first, t_list *third);
void			sort_b_top_three_third_biggest(t_list **a_stack,
					t_list **b_stack, t_list *first, t_list *second);

void			sort_three(t_list **a_stack);
void			sort_a_top_three(t_list **a_stack);
void			sort_a_top_three_first_biggest(t_list **a_stack,
					t_list *second, t_list *third);
void			sort_a_top_three_second_biggest(t_list **a_stack,
					t_list *first, t_list *third);
void			sort_a_top_three_third_biggest(t_list **a_stack,
					t_list *first, t_list *second);

void			quick_sort(t_list **a_stack, t_list **b_stack);
void			shortest_rotations(t_list **stack, unsigned int count_back,
					void (*r)(t_list **), void (*rr)(t_list **));
unsigned int	find_pivot(unsigned int min, unsigned int max);

float			check_order(t_list **stack, unsigned int min, unsigned int max,
					int ascending);
float			check_order_stack_a(t_list **stack);

void			divide_a(t_list **a_stack, t_list **b_stack, unsigned int a_min,
					unsigned int a_max);
unsigned int	divide_a_with_pivot(t_list **a_stack, t_list **b_stack,
					unsigned int pivot, unsigned int a_min);

void			divide_b(t_list **a_stack, t_list **b_stack, unsigned int b_min,
					unsigned int b_max);
unsigned int	divide_b_with_pivot(t_list **a_stack, t_list **b_stack,
					unsigned int pivot, unsigned int b_max);
void			sort_b_two(t_list **a_stack, t_list **b_stack);

int				error(void);
int				size_of_number(int num);
long			distance_from_zero(long position);

#endif
