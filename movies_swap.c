// sa	swap top two of stack A
// sb	swap top two of stack B
// ss	sa + sb simultaneously
// pa	push top from B → A
// pb	push top from A → B
// ra	rotate A (first → bottom)
// rb	rotate B
// rr	ra + rb
// rra	reverse rotate A (last → top)
// rrb	reverse rotate B
// rrr	rra + rrb
#include "push_swap.h"

void    swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    first = *stack;
    second = (*stack)->next;

    first->next = second->next;
    second->next = first;
}

void    sa(t_node **a)
{
    swap(a);
    write(1, "sa\n", 3);
}
void    sb(t_node **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

