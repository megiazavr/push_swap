/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:33:05 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/02 20:13:05 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*linked_list(int val)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		oopsie();
	n->val = val;
	n->idx = -1;
	n->next = NULL;
	return (n);
}

char	*list(int argc, char **argv, size_t len)
{
	int		i;
	int		j;
	char	*connected;
	char	*ptr;

	i = 1;
	while (i < argc)
		len += strlen(argv[i++]) + 1;
	connected = malloc(sizeof(char) * (len + 1));
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
	else
	{
		assign_indexes(a);
		radix(a, b, 0, 0);
	}
}

int	*parse_args(int argc, char **argv, int *count)
{
	char	**tokens;
	int		*vals;
	int		i;

	tokens = parse_args_part(argc, argv);
	areyoudig(tokens);
	*count = 0;
	while (tokens[*count])
		(*count)++;
	vals = malloc(sizeof(int) * (*count));
	if (!vals)
		oopsie();
	i = 0;
	while (i < *count)
	{
		vals[i] = (int)maximini(tokens[i]);
		i++;
	}
	free_array(tokens);
	dduupplliiccaattee(vals, *count);
	return (vals);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
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
	return (0);
}
