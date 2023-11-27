/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:57 by fbock             #+#    #+#             */
/*   Updated: 2023/11/27 13:04:03 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leak_checker(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_a_start;

	if (argc < 2)
		return (0);
	stack_a = check_and_allocate(argv);
	if (!stack_a)
		error_and_kill(NULL, NULL);
	sort_stack(&stack_a);
	stack_a_start = stack_a;
	free_all_nodes(&stack_a_start);
	return (0);
}

// ./push_swap 2 5 4 8 -2147483649

// atexit(leak_checker);

// ft_printf("\nResult: ");
// while (stack_a)
// {
// 	ft_printf("%i ", stack_a->content);
// 	stack_a = stack_a->next;
// }
// ft_printf("\n");
