/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:06:22 by fbock             #+#    #+#             */
/*   Updated: 2023/11/20 11:20:19 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rra(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	*stack_a = NULL;
	while (*stack_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		//*stack_b = (*stack_b)->next;
	}
}

