#include <push_swap.h>

t_list	*initialize_stack(char *argv[])
{
	int		i;
	t_list	*head;
	t_list	*temp;
	char	*str_next;

	i = 1;
	head = NULL;
	temp = NULL;
	while (argv[i])
	{
		str_next = argv[i];
		while (*str_next)
		{
			str_next = check_and_add_number(str_next, &head);
			if (str_next == NULL)
				return (NULL);
		}
		++i;
	}
	return (head);
}

char	*check_and_add_number(char *str_next, t_list **head)
{
	char	*str;
	t_list	*temp;

	temp = NULL;
	str = str_next;
	str_next = check_atoi(str);
	if (str_next == NULL)
	{
		stack_clear(head);
		return (NULL);
	}
	temp = add_to_stack(str, head);
	if (temp == NULL)
	{
		stack_clear(head);
		return (NULL);
	}
	return (str_next);
}

char	*check_atoi(char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = skip_whitespace_and_sign(str, &sign);
	while (is_cifer(str[i]))
		i++;
	if ((str[i] && str[i] != ' ') || (i > 0 && !is_cifer(str[i - 1])))
		return (NULL);
	return (&str[i]);
}

int	is_cifer(char num)
{
	if (num >= '0' && num <= '9')
		return (1);
	return (0);
}


