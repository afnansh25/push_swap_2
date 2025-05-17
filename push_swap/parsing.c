/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashaheen <ashaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:57:56 by ashaheen          #+#    #+#             */
/*   Updated: 2025/05/04 19:57:56 by ashaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	get_split_len(char **split)
{
	int	i = 0;
	while (split[i])
		i++;
	return (i);
}

static void	process_token(char *token, t_node **a, char **split)
{
	int	error;
	int	value;
	int	args;

	error = 0;
	args = get_split_len(split);
	if (!is_valid_input(token))
	{
		free_split(split, args);
		write_error(a);
	}
	value = ft_atoi(token, &error);
	if (error || !add_node(a, value))
	{
		free_split(split, args);
		write_error(a);
	}
}

static void	process_single_arg(char *arg, t_node **a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split || !*split)
		write_error(a);
	j = 0;
	while (split[j])
	{
		process_token(split[j], a, split);
		j++;
	}
	free_split(split, j);
}

void	parse_args(int ac, char **av, t_node **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!av[i][0] || is_all_spaces(av[i]))
			write_error(a);
		process_single_arg(av[i], a);
		i++;
	}
	if (has_duplicate(*a))
		write_error(a);
	assign_indexes(*a);
}
