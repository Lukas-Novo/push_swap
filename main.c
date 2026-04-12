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
#include <stdio.h>

// kroky nize zopakovat argc-krat
// brat jednotlive argumenty z argv
// zkontrolovat je, jestli jsou int
// prevezt je na int

// vytvorit stack a o velikosti argc (double-linked list dokola),
// ve kterem budou vsechny z argv

// vytvorit stack b (ukazatel na nej) (sam by se mel vytvorit
// s prvnim pridanim int ze stacku b)

int	main(int argc, char *argv[])
{
	t_list	*a_stack;

	a_stack = check_input(argc, argv);
	if (!a_stack)
		return (error());
	
	int	i = 1;
	while (argv[i])
	{
		printf("%s ", argv[i]);
		++i;
	}

	return (0);
}

int	check_input(int argc, char *argv[])
{
	int	i;
	t_list	*head;
	t_list	*temp;
	char *str;
	char *str_next;

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
				return (0);
			}
			temp = ft_lstnew(ft_atoi(str), head);
			if (head == NULL)
				head = temp;
			if (temp == NULL)
			{
				// VYMAZAT LIST!!!
				return (0);
			}
			str = str_next;
		}
		++i;
	}
	return (1);
}

int	check_atoi(char *str)
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
		return (1);
	if (str[i])
		return (2);	
	return (0);
}

