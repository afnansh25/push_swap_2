/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:57:37 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:57:39 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	add_node(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = create_node(value);
	if (!new)
		return (0);
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	return (1);
}

int	stack_sorted(t_node *s)
{
	while (s && s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*min;
	int		index;
	int		found;

	index = 0;
	while (1)
	{
		min = NULL;
		current = stack;
		found = 0;
		while (current)
		{
			if (current->index == -1)
			{
				if (!min || current->value < min->value)
					min = current;
				found = 1;
			}
			current = current->next;
		}
		if (!found)
			break ;
		min->index = index++;
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	int	len;

	if (stack_sorted(*a))
		return ;
	len = stack_len(*a);
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
