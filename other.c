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

int	skip_whitespace_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -*sign;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (i);
}