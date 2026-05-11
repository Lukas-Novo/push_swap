# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 17:12:00 by lnovotny          #+#    #+#              #
#    Updated: 2026/05/06 19:08:03 by lnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
SRCS_LIST = add_to_stack.c stack_clear.c stack_size.c
SRCS_OPERATIONS = push.c revers_rotations.c rotations.c swap.c
SRCS_QUICK_SORT = divide_a.c divide_b.c quick_sort.c sort_a_top_three.c sort_b_top_three.c
SRCS = check_order.c chunk_sort.c ft_atoi.c initialize_stack.c main.c other.c \
	$(addprefix ./list/, $(SRCS_LIST)) \
	$(addprefix ./operations/, $(SRCS_OPERATIONS)) \
	$(addprefix ./quick_sort/, $(SRCS_QUICK_SORT))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re