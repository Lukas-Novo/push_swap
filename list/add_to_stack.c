/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:08:22 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/18 18:43:49 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_to_stack(char *arg, t_list **stack)
{
	t_list	*new;
	int		original;

	original = ft_atoi(arg);
	if (check_overflow(arg, original))
		return (NULL);
	new = create_node(original);
	if (new == NULL)
		return (NULL);
	if (*stack == NULL)
	{
		*stack = new;
		return (new);
	}
	return (connect_node(stack, new));
}

int	check_overflow(char *str, int original)
{
	int	i;
	int	sign;
	int size_original;

	sign = 1;
	i = skip_whitespace_and_sign(str, &sign);
	size_original = size_of_number(original);
	if (!check_size(&str[i], size_original))
		return (1);
	if ((sign > 0 && original < 0) || (sign < 0 && original > 0))
		return (1);
	while (size_original > 0)
	{
		if (str[size_original - 1 + i] != (original % 10) * sign + '0')
			return (1);
		--size_original;
		original = original / 10;
	}
	if (size_original > 0)
		return (1);
	return (0);
}

int	check_size(char *str, int size_num)
{
	while (*str && *str != ' ' && *str != '\t' && *str != '\v'
		&& *str != '\f' && *str != '\r' && *str != '\n' && size_num > 0)
	{
		--size_num;
		++str;
	}
	if ((*str == '\0' || *str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n') && size_num == 0)
		return (1);
	if ((*str == '\0' || *str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n') && size_num == 0)
		return (1);
	return (0);
}

t_list	*create_node(int original)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->original = original;
	new->converted = 1;
	new->prev = new;
	new->next = new;
	return (new);
}

t_list	*connect_node(t_list **stack, t_list *new)
{
	t_list	*pars;

	pars = *stack;
	new->next = *stack;
	new->prev = (*stack)->prev;
	(new->next)->prev = new;
	(new->prev)->next = new;
	while (pars != new)
	{
		if (new->original > pars->original)
			new->converted += 1;
		else if (new->original < pars->original)
			pars->converted += 1;
		else
			return (NULL);
		pars = pars->next;
	}
	return (new);
}
