/* ************************************************************************** */
/*                                                                            */
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
	if (!check_input(argc, argv))
		return (error());
	
	int	i = 1;
	while (argv[i])
	{
		printf("%s ", argv[i]);
		++i;
	}

	return (0);
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
	if (str[i])
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
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
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	return (sign * nb);
}

int error()
{
	write(1, "Error\n", 6);
	return (1);
}

int	check_input(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_atoi(argv[i]))
			return (0);
		++i;
	}
	return (1);
}
