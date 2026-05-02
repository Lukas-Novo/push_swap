/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:38:21 by lnovotny          #+#    #+#             */
/*   Updated: 2026/03/28 18:10:58 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list			*a_stack;
	t_list			*b_stack;
	unsigned int	total_size;

	a_stack = initialize_stack(argv);
	b_stack = NULL;
	if (!(a_stack))
		return (error());
	total_size = stack_size(&a_stack);
	if (total_size < 6)
		quick_sort(&a_stack, &b_stack);
	else if (total_size < 200)
		chunk_sort(&a_stack, &b_stack);
	else
		quick_sort(&a_stack, &b_stack);
	stack_clear(&a_stack);
	stack_clear(&b_stack);
	return (0);
}
