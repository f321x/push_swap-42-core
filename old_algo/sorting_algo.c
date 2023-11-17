/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:46 by fbock             #+#    #+#             */
/*   Updated: 2023/11/13 13:55:49 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t			smallest_nbr_i;
	size_t			size_stack;

	size_stack = stack_size(*stack_a);
	smallest_nbr_i = smallest_nbr_index(*stack_a);
	if ((size_stack / 2) > smallest_nbr_i)
	{
		while (smallest_nbr_i > 0)
		{
			ra(stack_a);
			smallest_nbr_i--;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (smallest_nbr_i > 0)
		{
			rra(stack_a);
			smallest_nbr_i++;;
			if (smallest_nbr_i > (size_stack - 1))
				smallest_nbr_i = 0;
		}
		pb(stack_a, stack_b);
	}
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	while (stack_size(*stack_a) > 0)
		sort_to_b(stack_a, &stack_b);
	push_b_to_a(stack_a, &stack_b);
}
