#include "push_swap.h"

void	yongest(t_node **stack)
{
	t_node  *first;
	t_node  *second;
	t_node  *last;

	first = *stack;
	second = (*stack)->next;
	last = *stack;

	if (first < second && second < last)
	{
		sa(stack);
		ra(stack);
	}
	else if (first > second && second < last)
		sa(stack);
	else if (first < second && second > last)
		rra(stack);
	else if (first > second && second < last)
		ra(stack);
}

void	middle(t_node *a, t_node *b)
{
	if (size == 4)
		pb(a, b);
	else if (size == 5)
	{
		pb(a, b);
		pb(a, b);
	}
	micro_sort(a);
	if ((*b)->next && (*b)->val < (*b)->next->val)
		sb(b);
	while (*b)
		pa(a, b);
}

