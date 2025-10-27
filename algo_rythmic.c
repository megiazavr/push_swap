#include "push_swap.h"

//most sagnificant 
//less segnificant
int	list_size(t_node *stack)
{
	int lenght;

	lenght = 0;
	while (stack)
	{
		lenght++;
		stack = stack->next;
	}
	return (lenght);
}

int    whereismax(t_node *stack)
{
	int max;

	max = stack->idx;
	while (stack)
	{
		if (stack->idx > max)
			max = stack->idx;
		stack = stack->next;
	}
	return (max);
}

int    number_of_bits(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
}

void    radix(t_node **stack_a, t_node **stack_b)
{
	int i;
	int	j;
	int size;
	int	max_num;
	int	max_bits;
	int	num;

	i = 0;
	max_num = whereismax(*stack_a);
	max_bits = number_of_bits(max_num);
	printf("max = %d, max_bits = %d\n", max_num, max_bits);
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

