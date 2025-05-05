/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:57:23 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:57:26 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int *error)
{
	int				sign;
	unsigned long	result;
	int				i;

	sign = 1;
	result = 0;
	*error = 0;
	i = 0;
	if (!str[i])
		return (*error = 1, 0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*error = 1, 0);
		result = result * 10 + (str[i++] - '0');
		if (is_overflow(result, sign))
			return (*error = 1, 0);
	}
	return ((int)(result * sign));
}
