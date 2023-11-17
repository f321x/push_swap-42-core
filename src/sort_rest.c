/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:25 by fbock             #+#    #+#             */
/*   Updated: 2023/11/17 12:45:13 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_rest_3_a(t_stack_node **stack_a)
{
	size_t	index;

	index = biggest_nbr_index(*stack_a);
	if (index == 0)
		ra(stack_a);
	else if (index == 1)
		rr(stack_a, "rra");
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_stack(stack_a, "sa");
}

bool	sort_rest_3_b(t_stack_node **stack_b)
{
	size_t	index;

	index = biggest_nbr_index(*stack_b);
	if (index == 0)
		rb(stack_b);
	else if (index == 1)
		rr(stack_b, "rrb");
	if ((*stack_b)->content > (*stack_b)->next->content)
		swap_stack(stack_b, "sb");
}


