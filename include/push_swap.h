/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:54 by fbock             #+#    #+#             */
/*   Updated: 2023/11/23 14:52:33 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include <stdbool.h>

typedef struct s_stack_node {
	int		content;
	size_t	index;
	size_t	distance;
	bool	over_median;
	bool	shortest_distance;
	struct	s_stack_node *prev;
	struct	s_stack_node *next;
	struct	s_stack_node *stack_a_link;
}	t_stack_node;

// list_utils.c
void			ft_stackadd_front(t_stack_node **lst, t_stack_node *new);
void			ft_stackadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_stacknew(int content);
t_stack_node	*ft_stacklast(t_stack_node *lst);
void			free_all_nodes(t_stack_node **list);

// parse_arg.c
t_stack_node	*check_and_allocate(char **argv);
char			*combine_arguments(char **argv);
char			**format_args(char *combined_args);
t_stack_node	*populate_stack(char **numbers);

// parsing_utils.c
bool	check_duplicate(t_stack_node *stack_start, int value);
void	error_and_kill(char *msg, void *ptr_to_free, void **dptr_t_f);

// stack_ops.c
bool	push(t_stack_node **src, t_stack_node **dst);
void	pop(t_stack_node **stack);
void	swap(t_stack_node **stack);
void	rotate(t_stack_node **stack);
void	reverse_rotate(t_stack_node **stack);

// sorting_utils.c
void	rev_r(t_stack_node **stack, char* stack_name);
void	push_to_stack(t_stack_node **source, t_stack_node **dest, char* name);
void	rotate_stack(t_stack_node **stack, char *stack_name);
void	rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	rrr(t_stack_node **stack_a, t_stack_node **stack_b);

// sort_rest.c
void	sort_rest_3_a(t_stack_node **stack_a);
void	swap_stack(t_stack_node **stack, char *stack_name);


// algo_utils.c
void 	set_links_null(t_stack_node *stack);
void	init_stack_b(t_stack_node **stack_a, t_stack_node **stack_b);
void	calculate_distances(t_stack_node *stack_a, t_stack_node *stack_b);
void	link_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void	set_median_position(t_stack_node *stack_a, t_stack_node *stack_b);

// sorting_algo.c
void			set_indexes(t_stack_node *stack);
t_stack_node	*set_shortest_distance(t_stack_node *stack_b);
void			insert_node(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *node_to_push);
void			sort_stack(t_stack_node **stack_a);

// stack_utils.c
size_t	stack_size(t_stack_node *stack);
size_t	smallest_nbr_index(t_stack_node *stack);
size_t	biggest_nbr_index(t_stack_node *stack);
bool	check_sorted(t_stack_node *stack, size_t amount);



#endif
