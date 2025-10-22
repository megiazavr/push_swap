#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
    else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	append_node(t_node **stack, t_node *new)
{
	t_node	*tmp;
    if (!*stack)
    {
        *stack = new;
        return ;
    }
    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void	assign_indexes(t_node **stack)
{
    t_node *tmp;
    t_node *cmp;
    int index;

    tmp = *stack;
    while (tmp)
    {
        index = 0;
        cmp = *stack;
        while (cmp)
        {
            if (cmp->val < tmp->val)
                index++;
            cmp = cmp->next;
        }
        tmp->idx = index;
        printf("val=%d -> idx=%d\n", tmp->val, tmp->idx);
        tmp = tmp->next;
    }
}