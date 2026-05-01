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
char	*check_and_add_number(char *str_next, t_list **head)
{
	char	*str;
	t_list	*temp;

	temp = NULL;
	str = str_next;
	str_next = check_atoi(str);
	if (str_next == NULL)
	{
		stack_clear(head);
		return (NULL);
	}
	temp = add_to_stack(str, head);
	if (temp == NULL)
	{
		stack_clear(head);
		return (NULL);
	}
	return (str_next);
}

t_list	*initialize_stack(char *argv[])
{
	int		i;
	t_list	*head;
	t_list	*temp;
	char	*str_next;

	i = 1;
	head = NULL;
	temp = NULL;
	while (argv[i])
	{
		str_next = argv[i];
		while (*str_next)
		{
			str_next = check_and_add_number(str_next, &head);
			if (str_next == NULL)
				return (NULL);
		}
		++i;
	}
	return (head);
}

int	is_cifer(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}

char	*check_atoi(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = skip_whitespace_and_sign(str, &sign);
	while (is_cifer(str[i]))
		i++;
	if ((str[i] && str[i] != ' ') || (i > 0 && !is_cifer(str[i - 1])))
		return (NULL);
	return (&str[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	i = skip_whitespace_and_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (sign * nb);
}
