#include "push_swap.h"
#include <stdio.h>

void	ex(t_node **stack)
{
	t_node	*current;
	t_node	*noncurrent;
	int	index;

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
	t_node  *first;
	t_node  *second;
	t_node  *last;

	first = *stack;
	second = (*stack)->next;
	last = (*stack)->next->next;

	if (first->val > second->val && second->val < last->val && first->val < last->val)
		sa(stack);
	else if (first->val > second->val && second->val > last->val)
	{
		sa(stack);
		rra(stack);
	}
	else if (first->val > second->val && second->val < last->val && first->val > last->val)
		ra(stack);
	else if (first->val < second->val && second->val > last->val && first->val < last->val)
	{
		sa(stack);
		ra(stack);
	}
	else if (first->val < second->val && second->val > last->val && first->val > last->val)
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

