/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:32:55 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/03 17:21:46 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ind(t_node **stack)
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

t_node	*which_is_min(t_node **stack_a, int *pos_min)
{
	t_node	*min;
	t_node	*tmp;
	int		position;
	int		i;

	min = *stack_a;
	tmp = *stack_a;
	position = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->idx < min->idx)
		{
			min = tmp;
			position = i;
		}
		tmp = tmp->next;
		i++;
	}
	*pos_min = position;
	return (min);
}

void	yongest(t_node **stack)
{
	t_node	*st;
	t_node	*nd;
	t_node	*rd;

	st = *stack;
	nd = (*stack)->next;
	rd = (*stack)->next->next;
	if (st->val > nd->val && nd->val < rd->val && st->val < rd->val)
		sa(stack);
	else if (st->val < nd->val && nd->val > rd->val && st->val < rd->val)
	{
		sa(stack);
		ra(stack);
	}
	else if (st->val > nd->val && nd->val < rd->val && st->val > rd->val)
		ra(stack);
	else if (st->val > nd->val && nd->val > rd->val)
	{
		sa(stack);
		rra(stack);
	}
	else if (st->val < nd->val && nd->val > rd->val && st->val > rd->val)
		rra(stack);
}

void	middle(t_node **a, t_node **b, int size)
{
	t_node	*min;
	int		pos;

	ind(a);
	while (size > 3)
	{
		min = which_is_min(a, &pos);
		if (pos <= size / 2)
			while (*a != min)
				ra(a);
		else
			while (*a != min)
				rra(a);
		pb(a, b);
		size--;
	}
	yongest(a);
	while (*b)
		pa(a, b);
}
