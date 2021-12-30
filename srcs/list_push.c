/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:15:40 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/27 00:34:26 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_list_push_front(t_list **begin_list, t_list *newlist)
{
	new_len(*begin_list, 1);
	newlist->len = (*begin_list)->len;
	newlist->prev = (*begin_list)->prev;
	(*begin_list)->prev->next = newlist;
	(*begin_list)->prev = newlist;
	newlist->next = (*begin_list);
	*begin_list = newlist;
}

void	ft_list_pfront(t_list **begin_list, t_list *newlist)
{
	new_len(*begin_list, 1);
	newlist->len = (*begin_list)->len;
	newlist->prev = (*begin_list)->prev;
	(*begin_list)->prev = newlist;
	(*begin_list)->prev->next = newlist;
	newlist->next = (*begin_list);
	*begin_list = newlist;
}

void	ft_list_pushback(t_list *begin_list, int data, int i)
{
	t_list	*list_back;
	t_list	*list_current;
	int		j;

	list_back = malloc(sizeof(t_list));
	if (!list_back)
		return ;
	list_back->index_data = -1;
	list_current = begin_list;
	j = 1;
	while (j < i)
	{
		list_current = list_current->next;
		j++;
	}
	begin_list->prev = list_back;
	list_current->next = list_back;
	list_back->prev = list_current;
	list_back->data = data;
	list_back->next = begin_list;
	list_back->len = begin_list->len;
}
