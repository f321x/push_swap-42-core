/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:46 by fbock             #+#    #+#             */
/*   Updated: 2023/11/24 11:38:30 by fbock            ###   ########.fr       */
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

t_stack_node	*smallest_content_node(t_stack_node *stack)
{
	t_stack_node	*smallest_node;

	smallest_node = stack;
	while (stack)
	{
		if (stack->content < smallest_node->content)
			smallest_node = stack;
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*set_shortest_distance(t_stack_node *stack_b)
{
	t_stack_node	*best_node;

	best_node = stack_b;
	while (stack_b)
	{
		if (stack_b->distance < best_node->distance)
			best_node = stack_b;
		stack_b = stack_b->next;
	}
	return (best_node);
}

void	insert_node(t_stack_node **stack_a, t_stack_node **stack_b,
			t_stack_node *node_to_push)
{
	if (!(node_to_push->over_median) && !(node_to_push->stack_a_link->over_median))
	{
		while (*stack_a != node_to_push->stack_a_link && *stack_b != node_to_push)
			rr(stack_a, stack_b);
	}
	else if (node_to_push->over_median && node_to_push->stack_a_link->over_median)
	{
		while (*stack_a != node_to_push->stack_a_link && *stack_b != node_to_push)
			rrr(stack_a, stack_b);
	}
	while (*stack_a != node_to_push->stack_a_link)
	{
		if (node_to_push->stack_a_link->over_median)
			rev_r(stack_a, "rra");
		else
			rotate_stack(stack_a, "ra");
	}
	while (*stack_b != node_to_push)
	{
		if (node_to_push->over_median)
			rev_r(stack_b, "rrb");
		else
			rotate_stack(stack_b, "rb");
	}
	push_to_stack(stack_b, stack_a, "pa");
}

// static void	print_stack(t_stack_node *stack, char *str)
// {
// 	ft_printf("Content %s: ", str);
// 	while (stack)
// 	{
// 		ft_printf(" %i ", stack->content);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

// static void print_links(t_stack_node *stack)
// {
// 	ft_printf("Links to: ");
// 	while (stack)
// 	{
// 		ft_printf(" %i ", stack->stack_a_link->content);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	t_stack_node	*node_to_push;

	stack_b = NULL;
	if (check_sorted(*stack_a, stack_size(*stack_a)))
		return ;
	init_stack_b(stack_a, &stack_b);
	// print_stack(*stack_a, "STACK A START ");
	while (stack_size(stack_b) > 0)
	{
		link_nodes(*stack_a, stack_b);
		set_indexes(*stack_a);
		set_indexes(stack_b);
		set_median_position(*stack_a, stack_b);
		calculate_distances(*stack_a, stack_b);
		node_to_push = set_shortest_distance(stack_b);  // remove uneccessary stuff

		// ft_printf("\n");
		// print_stack(stack_b, "B");
		// print_links(stack_b);
		// print_stack(*stack_a, "A");

		// ft_printf("Node to push content: %i \n", node_to_push->content);
		insert_node(stack_a, &stack_b, node_to_push);
	}
	while (*stack_a != smallest_content_node(*stack_a))
		rotate_stack(stack_a, "ra");
}

// ./push_swap 85 12 93 41 60 74 17 32 5 9 10 18 16 33 40 81 89 28 30 64
