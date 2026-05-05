# NAME = push_swap
# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# SFILES = 

make:
# 	cc -I. *.c list/*.c operations/*.c -o push_swap
	cc -I. *.c list/*.c operations/*.c quick_sort/*.c -o push_swap

# nutné dopsat