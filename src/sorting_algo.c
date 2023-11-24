/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:46 by fbock             #+#    #+#             */
/*   Updated: 2023/11/23 20:51:39 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexes(t_stack_node *stack)
{
	size_t	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

t_stack_node	*set_shortest_distance(t_stack_node *stack_b)
{
	t_stack_node	*best_node;

	best_node = stack_b;
	while (stack_b)
	{
		stack_b->shortest_distance = false;
		stack_b = stack_b->next;
	}
	stack_b = best_node;
	while (stack_b)
	{
		if (stack_b->distance < best_node->distance)
			best_node = stack_b;
		stack_b = stack_b->next;
	}
	best_node->shortest_distance = true;
	return (best_node);
}

void	insert_node(t_stack_node **stack_a, t_stack_node **stack_b,
			t_stack_node *node_to_push)
{
	while (node_to_push->over_median && node_to_push->stack_a_link->over_median
			&& node_to_push->index > 0 && node_to_push->stack_a_link->index > 0)
	{
		rrr(stack_a, stack_b);
		set_indexes(*stack_a);
		set_indexes(*stack_b);
	}
	while (!(node_to_push->over_median) && !(node_to_push->stack_a_link->over_median)
			&& node_to_push->index > 0 && node_to_push->stack_a_link->index > 0)
	{
		rr(stack_a, stack_b);
		set_indexes(*stack_a);
		set_indexes(*stack_b);
	}
	while (node_to_push->index > 0 && node_to_push->over_median)
	{
		rev_r(stack_b, "rrb");
		set_indexes(*stack_b);
	}
	while (node_to_push->index > 0 && !(node_to_push->over_median))
	{
		rotate_stack(stack_b, "rb");
		set_indexes(*stack_b);
	}
	while (node_to_push->stack_a_link->index > 0 && node_to_push->stack_a_link->over_median)
	{
		rev_r(stack_a, "rra");
		set_indexes(*stack_a);
	}
	while (node_to_push->stack_a_link->index > 0 && !(node_to_push->stack_a_link->index))
	{
		rotate_stack(stack_a, "ra");
		set_indexes(*stack_a);
	}
	// ft_printf("NTP CONTENT: %i\n", node_to_push->content);
	push_to_stack(stack_b, stack_a, "pa");
	// return ;
}

static void	print_stack(t_stack_node *stack)
{
	ft_printf("Content: ");
	while (stack)
	{
		ft_printf(" %i ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	t_stack_node	*node_to_push;

	stack_b = NULL;
	init_stack_b(stack_a, &stack_b);
	while (!check_sorted(*stack_a, stack_size(*stack_a)) || stack_size(stack_b) > 0)
	{
		print_stack(*stack_a);

		link_nodes(*stack_a, stack_b);
		set_indexes(*stack_a);
		set_indexes(stack_b);
		set_median_position(*stack_a, stack_b);
		calculate_distances(*stack_a, stack_b);
		node_to_push = set_shortest_distance(stack_b);
		insert_node(stack_a, &stack_b, node_to_push);
	}
}

// ./push_swap 85 12 93 41 60 74 17 32 5 9 10 18 16 33 40 81 89 28 30 64
