/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:07:19 by fbock             #+#    #+#             */
/*   Updated: 2023/11/13 13:48:49 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_stack_node **lst, t_stack_node *new)
{
	new->prev = NULL;
	if ((*lst))
	{
		new->next = (*lst);
		(*lst)->prev = new;
	}
	else
	{
		new->next = NULL;
	}
	*lst = new;
}

void	ft_stackadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last_element;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last_element = ft_stacklast(*lst);
		last_element->next = new;
		new->prev = last_element;
	}
}

t_stack_node	*ft_stacknew(int content)
{
	t_stack_node	*return_struct;

	return_struct = malloc(sizeof(t_stack_node));
	if (!return_struct)
		return (NULL);
	return_struct->prev = NULL;
	return_struct->content = content;
	return_struct->next = NULL;
	return (return_struct);
}

t_stack_node	*ft_stacklast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_all_nodes(t_stack_node **list)
{
	if (!list || !(*list))
		return ;
	while ((*list)->next)
	{
		*list = (*list)->next;
		free((*list)->prev);
	}
	free(*list);
}
