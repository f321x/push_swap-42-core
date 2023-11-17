/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:06:22 by fbock             #+#    #+#             */
/*   Updated: 2023/11/17 12:46:04 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rr(t_stack_node **stack, char* stack_name)
{
	reverse_rotate(stack);
	ft_printf("%s\n", stack_name);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}
