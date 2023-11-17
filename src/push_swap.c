/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:57 by fbock             #+#    #+#             */
/*   Updated: 2023/11/13 14:00:18 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_a_start;

	if (argc < 3)
		error_and_kill("Error", NULL, NULL);
	stack_a = check_and_allocate(argv);
	if (!stack_a)
		error_and_kill("Error", NULL, NULL);
	sort_stack(&stack_a);
	stack_a_start = stack_a;
	while (stack_a)
	{
		ft_printf("%i ", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	free_all_nodes(&stack_a_start);
	return (0);
}

/*
** Implement the push, pop, swap and rotate functions on this 'stack'. (A real stack has only push and pop.)
** For that, think for a moment what you'd like them to do.
** What should swap and rotate on a 1-element stack do?
** What should push with NULL be?
** What should be the result of popping an empty stack?
** And only if you've come up with rules for these cases, then start to finally write the code.
*/
