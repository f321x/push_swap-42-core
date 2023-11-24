/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:11:45 by fbock             #+#    #+#             */
/*   Updated: 2023/11/24 10:53:56 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_links_null(t_stack_node *stack)
{
	while (stack)
	{
		stack->stack_a_link = NULL;
		stack = stack->next;
	}
}

void	init_stack_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	size_stack_a;

	size_stack_a = stack_size(*stack_a);
	while (size_stack_a > 3)
	{
		push_to_stack(stack_a, stack_b, "pb");
		size_stack_a--;
	}
	sort_rest_3_a(stack_a);
}

void	calculate_distances(t_stack_node *stack_a, t_stack_node *stack_b)
{
	size_t	stack_size_b;
	size_t	stack_size_a;

	stack_size_a = stack_size(stack_a);
	stack_size_b = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->distance = stack_b->index;
		if (stack_b->over_median)
			stack_b->distance = stack_size_b - stack_b->index;
		if (stack_b->stack_a_link->over_median)
			stack_b->distance += stack_size_a - stack_b->stack_a_link->index;
		else
			stack_b->distance += stack_b->stack_a_link->index;
		stack_b = stack_b->next;
	}
}

void	link_nodes(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*stack_a_start;

	stack_a_start = stack_a;
	set_links_null(stack_b);
	while (stack_b)
	{
		stack_a = stack_a_start;
		while (stack_a)
		{
			if ((stack_a->content > stack_b->content
				&& stack_b->stack_a_link == NULL) || ((stack_a->content >
				stack_b->content && stack_b->stack_a_link->content
				> stack_a->content)))
				stack_b->stack_a_link = stack_a;
			stack_a = stack_a->next;
		}
		if (stack_b->stack_a_link == NULL)
			stack_b->stack_a_link = smallest_content_node(stack_a_start);
		stack_b = stack_b->next;
	}
}

void	set_median_position(t_stack_node *stack_a, t_stack_node *stack_b)
{
	size_t	median_a;
	size_t	median_b;

	median_a = stack_size(stack_a) / 2;
	median_b = stack_size(stack_b) / 2;
	while (stack_a)
	{
		if (stack_a->index < median_a)
			stack_a->over_median = false;
		else
			stack_a->over_median = true;
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		if (stack_b->index < median_b)
			stack_b->over_median = false;
		else
			stack_b->over_median = true;
		stack_b = stack_b->next;
	}
}
