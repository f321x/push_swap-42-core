/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:19:23 by fbock             #+#    #+#             */
/*   Updated: 2023/11/27 13:12:00 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*check_and_allocate(char **argv)
{
	t_stack_node	*stack_a;
	char			*combined_args;
	char			**formatted_args;
	char			**formatted_args_start;

	combined_args = combine_arguments(argv);
	if (!combined_args)
		error_and_kill(NULL, NULL);
	formatted_args = format_args(combined_args);
	if (!formatted_args[0])
		error_and_kill(NULL, (void **)formatted_args);
	stack_a = populate_stack(formatted_args, 0);
	formatted_args_start = formatted_args;
	while (*formatted_args != NULL)
	{
		free(*formatted_args);
		formatted_args++;
	}
	free(formatted_args_start);
	if (!stack_a)
		error_and_kill(NULL, NULL);
	return (stack_a);
}

char	*combine_arguments(char **argv)
{
	char	*buffer;
	char	*result_unsplit;
	size_t	index;

	index = 1;
	buffer = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (NULL);
	while (argv[index])
	{
		result_unsplit = ft_strjoin(buffer, argv[index++]);
		free(buffer);
		if (!result_unsplit)
			error_and_kill(NULL, NULL);
		buffer = result_unsplit;
		if (argv[index])
		{
			result_unsplit = ft_strjoin(buffer, " ");
			free(buffer);
			if (!result_unsplit)
				error_and_kill(NULL, NULL);
			buffer = result_unsplit;
		}
	}
	return (result_unsplit);
}

char	**format_args(char *combined_args)
{
	char	**splitted_args;
	size_t	string;
	size_t	character;

	string = -1;
	splitted_args = ft_split(combined_args, ' ');
	if (!splitted_args)
		error_and_kill((void *)combined_args, NULL);
	free(combined_args);
	while (splitted_args[++string])
	{
		if (ft_strlen(splitted_args[string]) > 11)
			error_and_kill(NULL, (void **)splitted_args);
		character = 0;
		if (!ft_isnumeric(splitted_args[string]) ||
			(ft_atoi(splitted_args[string]) < INT_MIN) ||
			(ft_atoi(splitted_args[string]) > INT_MAX))
		{
			error_and_kill(NULL, (void **)splitted_args);
		}
	}
	return (splitted_args);
}

t_stack_node	*populate_stack(char **numbers, size_t number_index)
{
	t_stack_node	*new_stack;
	t_stack_node	*buffer;
	long long		number;

	new_stack = ft_stacknew(ft_atoi(numbers[number_index++]));
	if (!new_stack)
		error_and_kill(NULL, (void **)numbers);
	while (numbers[number_index])
	{
		number = ft_atoi(numbers[number_index++]);
		buffer = ft_stacknew((int)number);
		if (!buffer)
		{
			free_all_nodes(&new_stack);
			error_and_kill(NULL, (void **)numbers);
		}
		ft_stackadd_back(&new_stack, buffer);
		if (check_duplicate(new_stack, number))
		{
			free_all_nodes(&new_stack);
			return (NULL);
		}
	}
	return (new_stack);
}
