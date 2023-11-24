/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:06:22 by fbock             #+#    #+#             */
/*   Updated: 2023/11/24 10:58:15 by fbock            ###   ########.fr       */
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
