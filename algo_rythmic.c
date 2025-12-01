/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rythmic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:32:50 by megiazar          #+#    #+#             */
/*   Updated: 2025/11/30 19:45:10 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_node *stack)
{
	int	lenght;

	lenght = 0;
	while (stack)
	{
		lenght++;
		stack = stack->next;
	}
	return (lenght);
}

int	whereismax(t_node *stack)
{
	int	max;

	max = stack->idx;
	while (stack)
	{
		if (stack->idx > max)
			max = stack->idx;
		stack = stack->next;
	}
	return (max);
}

int	number_of_bits(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
}

void	radix(t_node **stack_a, t_node **stack_b, int size, int num)
{
	int	i;
	int	j;
	int	max_num;
	int	max_bits;

	i = 0;
	max_num = whereismax(*stack_a);
	max_bits = number_of_bits(max_num);
	while (i < max_bits)
	{
		j = 0;
		size = list_size(*stack_a);
		while (j < size)
		{
			num = (*stack_a)->idx;
			if (((num >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
