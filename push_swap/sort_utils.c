/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:58:44 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:47 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_node(t_node *s)
{
	if (!s)
		return (NULL);
	while (s->next != NULL)
		s = s->next;
	return (s);
}

int	stack_len(t_node *s)
{
	int	len;

	len = 0;
	while (s)
	{
		len++;
		s = s->next;
	}
	return (len);
}

t_node	*findmax(t_node *s)
{
	t_node	*max;

	if (!s)
		return (NULL);
	max = s;
	while (s)
	{
		if (s->value > max->value)
			max = s;
		s = s->next;
	}
	return (max);
}

t_node	*findmin(t_node *s)
{
	t_node	*min;

	if (!s)
		return (NULL);
	min = s;
	while (s)
	{
		if (s->value < min->value)
			min = s;
		s = s->next;
	}
	return (min);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
