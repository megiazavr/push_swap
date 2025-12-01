/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movies_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:33:30 by megiazar          #+#    #+#             */
/*   Updated: 2025/11/30 19:23:56 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rra(t_node **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
