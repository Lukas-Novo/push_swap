make:
# 	cc -I. *.c list/*.c operations/*.c -o push_swap
	cc -g -fsanitize=address -I. *.c list/*.c operations/*.c quick_sort/*.c -o push_swap