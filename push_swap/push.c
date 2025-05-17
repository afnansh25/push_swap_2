/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:58:10 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:12 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **des, t_node **src)
{
	t_node	*temp_node;

	if (!src || !*src)
		return ;
	temp_node = *src;
	*src = (*src)->next;
	if (!*des)
	{
		temp_node->next = NULL;
		(*des) = temp_node;
	}
	else
	{
		temp_node->next = *des;
		*des = temp_node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
