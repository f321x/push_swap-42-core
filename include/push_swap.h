/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:54 by fbock             #+#    #+#             */
/*   Updated: 2023/11/17 12:47:40 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>

typedef struct s_stack_node {
	int		content;
	struct	s_stack_node *prev;
	struct	s_stack_node *next;
}	t_stack_node;


t_stack_node	*ft_stacknew(int content);
void			ft_stackadd_front(t_stack_node **lst, t_stack_node *new);
void			pop(t_stack_node **stack);
bool			push(t_stack_node **src, t_stack_node **dst);
t_stack_node	*ft_stacklast(t_stack_node *lst);
void			swap(t_stack_node **stack);
void			rotate(t_stack_node **stack);
void			reverse_rotate(t_stack_node **stack);
void			free_all_nodes(t_stack_node **list);
char			*combine_arguments(char **argv);
t_stack_node	*populate_stack(char **numbers);
void			ft_stackadd_back(t_stack_node **lst, t_stack_node *new);
// void			is_numeric(char **formatted_args);
bool			check_duplicate(t_stack_node *stack_start, int value);
void			error_and_kill(char *msg, void *ptr_to_free, void **dptr_t_f);
t_stack_node	*check_and_allocate(char **argv);
char			**format_args(char *combined_args);
size_t			stack_size(t_stack_node *list);
void			sort_stack(t_stack_node **stack_a);
size_t			smallest_nbr_index(t_stack_node *stack);
void			ra(t_stack_node **stack_a);
void			rr(t_stack_node **stack, char* stack_name);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
// void			push_b_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
void			bubblesort(int *int_array, size_t size);
int				get_median(t_stack_node *stack, size_t amount);
bool			quicksort_b(t_stack_node **stack_a, t_stack_node **stack_b, size_t len);
bool			quicksort_a(t_stack_node **stack_a, t_stack_node **stack_b, size_t len);
void			rb(t_stack_node **stack_b);
void			pa(t_stack_node **stack_b, t_stack_node **stack_a);
void			swap_stack(t_stack_node **stack_a, char *stack);
bool			sort_rest_3_a(t_stack_node **stack_a);
bool			sort_rest_3_b(t_stack_node **stack_b);
size_t			biggest_nbr_index(t_stack_node *stack);
bool	check_sorted(t_stack_node *stack, size_t amount);

#endif
