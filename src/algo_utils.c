/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:11:45 by fbock             #+#    #+#             */
/*   Updated: 2023/11/27 11:10:36 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_links_null(t_stack_node *stack)
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
	if (size_stack_a == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (size_stack_a > 3)
		{
			push_to_stack(stack_a, stack_b, "pb");
			size_stack_a--;
		}
		sort_rest_3_a(stack_a);
	}
}

void	calculate_distances(t_stack_node *a, t_stack_node *b)
{
	size_t	stack_size_b;
	size_t	stack_size_a;

	stack_size_a = stack_size(a);
	stack_size_b = stack_size(b);
	while (b)
	{
		b->distance = b->index;
		if (b->over_median)
			b->distance = stack_size_b - b->index;
		if (b->stack_a_link->over_median)
			b->distance += stack_size_a - b->stack_a_link->index;
		else
			b->distance += b->stack_a_link->index;
		b = b->next;
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
					&& stack_b->stack_a_link == NULL) || ((stack_a->content
						> stack_b->content && stack_b->stack_a_link->content
						> stack_a->content)))
				stack_b->stack_a_link = stack_a;
			stack_a = stack_a->next;
		}
		if (stack_b->stack_a_link == NULL)
			stack_b->stack_a_link = smallest_content_node(stack_a_start);
		stack_b = stack_b->next;
	}
}

void	set_median_position(t_stack_node *a, t_stack_node *b)
{
	size_t	median_a;
	size_t	median_b;

	median_a = stack_size(a) / 2;
	median_b = stack_size(b) / 2;
	while (a)
	{
		if (a->index < median_a)
			a->over_median = false;
		else
			a->over_median = true;
		a = a->next;
	}
	while (b)
	{
		if (b->index < median_b)
			b->over_median = false;
		else
			b->over_median = true;
		b = b->next;
	}
}
