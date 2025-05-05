/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:58:19 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:58:19 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_maxbit(int nbr)
{
	int	bit;

	bit = 0;
	while (nbr > 0)
	{
		nbr >>= 1;
		bit++;
	}
	return (bit);
}

int	find_biggest(t_node *stack)
{
	int		max;
	t_node	*temp;

	if (!stack)
		return (-1);
	max = INT_MIN;
	temp = stack;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	biggest_n;
	int	i;
	int	j;
	int	size;

	biggest_n = find_biggest(*a);
	max_bits = find_maxbit(biggest_n);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack_len(*a);
		while (j++ < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(b, a);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
