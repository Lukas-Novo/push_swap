/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:44:12 by lnovotny          #+#    #+#             */
/*   Updated: 2025/11/19 18:42:47 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// OK

#include "push_swap.h"

// Delete original of lst and free lst

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->original);
	free(lst);
}
