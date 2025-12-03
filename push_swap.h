/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:14:09 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/03 17:49:01 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
}	t_node;

t_node	*linked_list(int val);
t_node	*which_is_min(t_node **stack_a, int *pos_min);
size_t	ft_strlen(const char *s);

int		main(int argc, char **argv);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_issorted(int *vals, int count);
int		word_count(const char *s);
int		*parse_args(int argc, char **argv, int *count);

int		list_size(t_node *stack);
int		whereismax(t_node *stack);
int		number_of_bits(int num);

long	maximini(const char *s);

char	**split(char *s);
char	*list(int argc, char **argv, size_t len);
char	*word(const char *s, int start, int end);
char	**parse_args_part(int argc, char *argv[]);

void	oopsie(void);
void	areyoudig(char **list, int i);
void	dduupplliiccaattee(int *head, int n);
void	append_node(t_node **stack, t_node *new);
void	free_stack(t_node **stack);
void	free_array(char **list);

void	ind(t_node **stack);
void	sort(t_node **a, t_node **b, int size);
void	yongest(t_node **stack);
void	middle(t_node **a, t_node **b, int size);

void	radix(t_node **stack_a, t_node **stack_b, int size, int num);
void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	push(t_node **stack_a, t_node **stack_b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rrotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif