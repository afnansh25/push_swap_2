/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:58:51 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:53 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	t_node	*max;

	max = findmax(*a);
	if (max == *a)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_four(t_node **a, t_node **b)
{
	int	pos;

	pos = find_pos(*a, 3);
	if (pos <= 4 / 2)
	{
		while ((*a)->index != 3)
			ra(a);
	}
	else
	{
		while ((*a)->index != 3)
			rra(a);
	}
	pb(b, a);
	sort_three(a);
	pa(a, b);
	ra(a);
}

void	sort_five(t_node **a, t_node **b)
{
    int	pos;

    pos = find_pos(*a, 0);
    if (pos <= 2)
        while (pos--) 
			ra(a);
    else
        while (pos++ < 5) 
			rra(a);
    pb(b, a);
    pos = find_pos(*a, 1);
    if (pos <= 1)
        while (pos--) 
			ra(a);
    else
        while (pos++ < 4) 
			rra(a);
    pb(b, a);
    sort_three(a);
    if ((*b)->value < (*b)->next->value)
        sb(b);
    pa(a, b);
    pa(a, b);
}

int	find_pos(t_node *stack, int big_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == big_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
