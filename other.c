/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:11:35 by lnovotny          #+#    #+#             */
/*   Updated: 2026/05/06 18:27:24 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_number(int num)
{
	int	size;

	size = 0;
	while (num)
	{
		++size;
		num = num / 10;
	}
	return (size);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

long	distance_from_zero(long position)
{
	if (position >= 0)
		return (position);
	else
		return (-position);
}
