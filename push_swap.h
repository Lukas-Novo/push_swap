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

typedef struct s_list
{
    int             original;
    unsigned int    converted;
    struct s_list   *prev;
    struct s_list   *next;
}   t_list

int error();
int	check_input(int argc, char *argv[]);
int	ft_atoi(const char *str);

#endif

