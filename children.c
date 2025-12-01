/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:32:55 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/01 16:45:55 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ex(t_node **stack)
{
	t_node	*current;
	t_node	*noncurrent;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		noncurrent = *stack;
		while (noncurrent)
		{
			if (current->val > noncurrent->val)
				index++;
			noncurrent = noncurrent->next;
		}
		current->idx = index;
		current = current->next;
	}
}

t_node	*which_is_min(t_node **stack_a)
{
	t_node	*min;
	t_node	*tmp;

	min = *stack_a;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->idx < min->idx)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	push_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*min_idx;

	if (!stack_a || !*stack_a)
		return ;
	min_idx = which_is_min(stack_a);
	while (*stack_a != min_idx)
		ra(stack_a);
	pb(stack_a, stack_b);
}

void	yongest(t_node **stack)
{
	int	st;
	int	nd;
	int	rd;

	st = (*stack)->val;
	nd = (*stack)->next->val;
	rd = (*stack)->next->next->val;
	if (st > nd && nd < rd && st < rd)
		sa(stack);
	else if (st > nd && nd > rd)
	{
		sa(stack);
		rra(stack);
	}
	else if (st > nd && nd < rd && st > rd)
		ra(stack);
	else if (st < nd && nd > rd && st < rd)
	{
		sa(stack);
		ra(stack);
	}
	else if (st < nd && nd > rd && st > rd)
		rra(stack);
}

void	middle(t_node **a, t_node **b, int size)
{
	t_node	*min;

	ex(a);
	while (size > 3)
	{
		min = which_is_min(a);
		while (*a != min)
			ra(a);
		pb(a, b);
		size--;
	}
	yongest(a);
	while (*b)
		pa(a, b);
}
