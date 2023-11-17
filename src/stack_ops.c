/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:18:55 by fbock             #+#    #+#             */
/*   Updated: 2023/11/13 13:33:03 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes the first node of a stack to the top of another stack
** and deletes the node from the original stacks top
*/
bool	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node *new;

	if (!(*src))
		return (false);
	new = ft_stacknew((*src)->content);
	if (!new)
		return (false);
	ft_stackadd_front(dst, new);
	pop(src);
	return (true);
}

/*
** Deletes (pops) a node from the top of a stack
*/
void	pop(t_stack_node **stack)
{
	t_stack_node *buffer;

	if (stack && *stack)
	{
		buffer = *stack;
		*stack = (*stack)->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		free(buffer);
	}
}

/*
** Swaps the first two elements of a stack
*/
void	swap(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = (*stack);
	second = (*stack)->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

/*
** Rotates a stack so the first element will be the last one and
** and the second one will be the new top
*/
void	rotate(t_stack_node **stack)
{
	t_stack_node *last_node;
	t_stack_node *first_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last_node = ft_stacklast(*stack);
	first_node = *stack;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->next = NULL;
	first_node->prev = last_node;
}

/*
** Shift down all elements of the stack by 1.
** The last element becomes the first one.
*/
void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last_node = ft_stacklast(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	last_node->next = *stack;
	*stack = last_node;
}
