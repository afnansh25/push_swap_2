/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:57:17 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:57:19 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_overflow(unsigned long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
		return (1);
	if (sign == -1 && result > (unsigned long)INT_MAX + 1)
		return (1);
	return (0);
}

void	write_error(t_node **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}
