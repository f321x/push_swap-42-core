/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:09:50 by fbock             #+#    #+#             */
/*   Updated: 2023/11/27 12:41:55 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	is_numeric(char **formatted_args)
// {
// 	size_t	string_index;
// 	size_t	char_index;

// 	string_index = 0;
// 	while (formatted_args[string_index])
// 	{
// 		char_index = 0;
// 		while (formatted_args[string_index][char_index])
// 		{
// 			if (!ft_isdigit(formatted_args[string_index][char_index]))
// 				error_and_kill("Argument is not a digit.");
// 			char_index++;
// 		}
// 		string_index++;
// 	}
// }

bool	check_duplicate(t_stack_node *stack_start, int value)
{
	int	duplicate;

	duplicate = 0;
	while (stack_start && duplicate < 2)
	{
		if (stack_start->content == value)
			duplicate++;
		stack_start = stack_start->next;
	}
	if (duplicate > 1)
		return (true);
	return (false);
}

void	error_and_kill(void *ptr_to_free, void **dptr_t_f)
{
	void	**dptr_to_free_start;

	dptr_to_free_start = dptr_t_f;
	ft_putstr_fd("Error\n", 2);
	if (ptr_to_free)
		free(ptr_to_free);
	while (dptr_t_f && *dptr_t_f)
	{
		free(*dptr_t_f);
		dptr_t_f++;
	}
	if (dptr_to_free_start)
		free(dptr_to_free_start);
	exit(EXIT_FAILURE);
}
