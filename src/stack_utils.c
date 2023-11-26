/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:12:57 by fbock             #+#    #+#             */
/*   Updated: 2023/11/26 23:30:03 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_size(t_stack_node *stack)
{
	size_t	size;

	size = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

size_t	smallest_nbr_index(t_stack_node *stack)
{
	size_t	index_smallest_number;
	size_t	index;
	int		current_smallest;

	index_smallest_number = 0;
	index = 0;
	current_smallest = stack->content;
	while (stack)
	{
		if (stack->content < current_smallest)
		{
			index_smallest_number = index;
			current_smallest = stack->content;
		}
		stack = stack->next;
		index++;
	}
	return (index_smallest_number);
}

size_t	biggest_nbr_index(t_stack_node *stack)
{
	size_t	index_biggest_number;
	size_t	index;
	int		current_biggest;

	index_biggest_number = 0;
	index = 0;
	current_biggest = stack->content;
	while (stack)
	{
		if (stack->content > current_biggest)
		{
			index_biggest_number = index;
			current_biggest = stack->content;
		}
		stack = stack->next;
		index++;
	}
	return (index_biggest_number);
}

bool	check_sorted(t_stack_node *stack, size_t amount)
{
	while (amount > 0 && stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
		amount--;
	}
	return (true);
}
