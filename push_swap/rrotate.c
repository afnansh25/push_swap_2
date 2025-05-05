/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:58:33 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:35 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = last_node(*s);
	if (!last)
		return ;
	while (first->next != last)
		first = first->next;
	first->next = NULL;
	last->next = *s;
	*s = last;
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
