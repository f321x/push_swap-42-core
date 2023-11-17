/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:46 by fbock             #+#    #+#             */
/*   Updated: 2023/11/17 13:16:44 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	quicksort_a(t_stack_node **stack_a, t_stack_node **stack_b, size_t len)
{
	if (check_sorted(*stack_a, len))
		return (true);
	if (stack_size(*stack_a) <= 3)
		return (sort_rest_3_a(stack_a));

}

bool quicksort_b(t_stack_node **stack_a, t_stack_node **stack_b, size_t len)
{

}

int	get_median(t_stack_node *stack, size_t amount)
{
	int				*substack_numbers;
	int				median_number;
	size_t			substack_index;

	substack_numbers = malloc(sizeof(int) * amount);
	// if (!substack_numbers)
	// 	return (NULL);  // check later !!!
	substack_index = 0;
	while (substack_index < amount && stack)
	{
		substack_numbers[substack_index] = stack->content;
		stack = stack->next;
		substack_index++;
	}
	bubblesort(substack_numbers, amount);
	if (amount % 2 != 0)
		median_number = substack_numbers[amount / 2];
	else
		median_number = (substack_numbers[amount / 2] + substack_numbers[(amount / 2) + 1]) / 2;
	free(substack_numbers);
	return (median_number);
}

void	bubblesort(int *int_array, size_t size)
{
	uint8_t	is_sorted;
	size_t	index;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		index = 0;
		while (index < (size - 1))
		{
			if (int_array[index] > int_array[index + 1])
			{
				is_sorted = 0;
				int_array[index] = int_array[index] ^ int_array[index + 1];
				int_array[index + 1] = int_array[index + 1] ^ int_array[index];
				int_array[index] = int_array[index + 1] ^ int_array[index];
			}
			index++;
		}
	}
}

void	sort_stack(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	quicksort_a(stack_a, &stack_b, stack_size(*stack_a));

}
