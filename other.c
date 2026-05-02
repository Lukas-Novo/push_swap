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

int error()
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
