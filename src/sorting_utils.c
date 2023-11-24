/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ***REMOVED*** <***REMOVED***@student.***REMOVED***.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:06:22 by ***REMOVED***             #+#    #+#             */
/*   Updated: 2023/11/23 12:59:51 by ***REMOVED***            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_r(t_stack_node **stack, char* stack_name)
{
	reverse_rotate(stack);
	ft_printf("%s\n", stack_name);
}

void	push_to_stack(t_stack_node **source, t_stack_node **dest, char* name)
{
	push(source, dest);
	ft_printf("%s\n", name);
}

void	rotate_stack(t_stack_node **stack, char *stack_name)
{
	rotate(stack);
	ft_printf("%s\n", stack_name);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
