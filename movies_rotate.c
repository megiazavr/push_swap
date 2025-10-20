// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.
#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = *stack;
	second = (*stack)->next;
	last = *stack;

	while (last->next)
		last = last->next;
	(*stack) = second;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}