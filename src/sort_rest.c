/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:30:25 by fbock             #+#    #+#             */
/*   Updated: 2023/11/27 11:24:52 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack_node **stack, char *stack_name)
{
	swap(stack);
	ft_printf("%s\n", stack_name);
}

void	sort_rest_3_a(t_stack_node **stack_a)
{
	size_t	index;

	index = biggest_nbr_index(*stack_a);
	if (index == 0)
		rotate_stack(stack_a, "ra");
	else if (index == 1)
		rev_r(stack_a, "rra");
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_stack(stack_a, "sa");
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	index;

	while (stack_size(*stack_a) > 3)
	{
		index = smallest_nbr_index(*stack_a);
		while (*stack_a != smallest_content_node(*stack_a))
		{
			if (index < 3)
				rotate_stack(stack_a, "ra");
			else
				rev_r(stack_a, "rra");
		}
		push_to_stack(stack_a, stack_b, "pb");
	}
	sort_rest_3_a(stack_a);
	while (*stack_b)
		push_to_stack(stack_b, stack_a, "pa");
}

// bool	sort_rest_3_b(t_stack_node **stack_b)
// {
// 	size_t	index;

// 	index = smallest_nbr_index(*stack_b);
// 	if (index == 0)
// 		rb(stack_b);
// 	else if (index == 1)
// 		rr(stack_b, "rrb");
// 	if ((*stack_b)->content < (*stack_b)->next->content)
// 		swap_stack(stack_b, "sb");
// }
