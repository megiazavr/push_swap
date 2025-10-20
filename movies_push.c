// pa	push top from B → A
// pb	push top from A → B

// poluchaetsya stack a 3 2 1 stack b empty;
// nuzhno iz stack a v stack b 
// iz stack a nuzhno perenesti second o first i vse perenesti naverh 
#include "push_swap.h"

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_a;

	if (!stack_a || !*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}