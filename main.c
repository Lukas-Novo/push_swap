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

	a_stack = check_input(argc, argv);
	b_stack = NULL;
	if (!(a_stack))
		return (error());
	// total_size = stack_size(a_stack);
	// print_stack(a_stack);
	// insertion_sort(a_stack, b_stack);
	merge_sort(&a_stack, &b_stack);
	// print_stack(a_stack);
	return (0);
}

t_list	*check_input(int argc, char *argv[])
{
	int		i;
	t_list	*head;
	t_list	*temp;
	char	*str;
	char	*str_next;

	i = 1;
	head = NULL;
	temp = NULL;
	while (argv[i])
	{
		str = argv[i];
		str_next = str;
		while (*str_next)
		{
			str_next = check_atoi(str);
			if (str_next == NULL)
			{
				// VYMAZAT LIST!!!
				return (NULL);
			}
			temp = stack_a_alloc(ft_atoi(str), head);
			if (head == NULL)
				head = temp;
			if (temp == NULL)
			{
				// VYMAZAT LIST!!!
				return (NULL);
			}
			str = str_next;
		}
		++i;
	}
	return (head);
}

char	*check_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && str[i] != ' ')
		return (NULL);
	return (&str[i]);
}

