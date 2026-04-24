make:
	cc -g -fsanitize=address -I. *.c list/*.c operations/*.c -o push_swap