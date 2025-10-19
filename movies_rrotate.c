// rrotate	reverse rotate A (last → top)
// rrb	reverse rotate B
// rrr	rrotate + rrb

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
//rrr : rra and rrb at the same time.

#include "push_swap.h"

void	rrotate(t_node **stack)
{
	t_node	*first;
	t_node	*notlast;
	t_node	*last;

	first = *stack;
	last = *stack;

	while (last->next)
	{
		notlast = last;
		last = last->next;
	}
	notlast->next = NULL;
	last->next = first;
	*stack = last;
}

void	rra(t_node *a)
{
	rrotate(&a);
	write(1, "rra\n", 4);
}
void	rrb(t_node *b)
{
	rrotate(&b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node *a, t_node *b)
{
	rrotate(&a);
	rrotate(&b);
	write(1, "rrr\n", 4);
}