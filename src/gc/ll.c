/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgerbaul <jgerbaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:14:05 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/21 02:12:55 by jgerbaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_gc	*gc_memory(t_gc *node, int code);

void	free_node(t_gc *node)
{
	if (!node)
		return ;
	free(node->alloc);
	free(node);
}

t_gc	*ll_add_back(t_gc *lst, t_gc *node)
{
	t_gc	*new_lst;

	if (!lst)
		return (node);
	new_lst = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = node;
	return (new_lst);
}

t_gc	*remove_idx(size_t idx, t_gc *lst)
{
	t_gc		*past;
	t_gc		*new_lst;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	else if (idx == 0)
	{
		new_lst = lst->next;
		free_node(lst);
		return (new_lst);
	}
	while (idx)
	{
		past = lst;
		lst = lst->next;
		idx--;
	}
	past->next = lst->next;
	free_node(lst);
	return (new_lst);
}
