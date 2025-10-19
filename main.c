#include "push_swap.h"

t_node	*linked_list(int val)
{
	t_node *n;

	n = malloc(sizeof(t_node));
	if (!n)
		oopsie();
	n->val = val;
	n->idx = -1;
	n->next = NULL;
	return (n);
}

char	*list(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	len;
	char	*connected;
	char	*ptr;

	i = 1;
	len = 0;
	while (i < argc)
		len += strlen(argv[i++]) + 1;
	connected = malloc(len + 1);
	if (!connected)
		oopsie();
	ptr = connected;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			*ptr++ = argv[i][j++];
		if (i < argc - 1)
			*ptr++ = ' ';
		i++;
	}
	*ptr = '\0';
	return (connected);
}

void	sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		yongest(a);
	else if (size <= 5)
		middle(a, b, size);
}

int	main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;
	int		*vals;
	int		count;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	vals = parse_args(argc, argv, &count);
	if (ft_issorted(vals, count))
		return (free(vals), 0);
	i = 0;
	while (i < count)
		append_node(&a, linked_list(vals[i++]));
	sort(&a, &b, count);
	free(vals);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

