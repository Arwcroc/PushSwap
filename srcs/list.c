/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:17:25 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/27 00:41:16 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*list_init(char **arg, int len)
{
	t_list	*list_begin;
	int		i;

	list_begin = malloc(sizeof(t_list));
	if (!list_begin)
		return (NULL);
	list_begin->len = len;
	list_begin->prev = list_begin;
	list_begin->index_data = -1;
	list_begin->data = ft_strtoi(arg[0]);
	list_begin->next = list_begin;
	i = 1;
	while (i < len)
	{
		ft_list_pushback(list_begin, ft_strtoi(arg[i]), i);
		i++;
	}
	return (list_begin);
}

void	set_index(t_list *list)
{
	t_list	*current_list;
	int		i;
	int		j;
	int		min;
	int		index;

	index = 0;
	j = 0;
	while (j++ < list->len)
	{
		min = INT_MAX;
		current_list = list;
		i = 0;
		while (i++ < list->len)
		{
			if (current_list->index_data == -1 && current_list->data < min)
				min = current_list->data;
			current_list = current_list->next;
		}
		if (ft_list_at(list, min))
			ft_list_at(list, min)->index_data = index;
		index++;
	}
}

void	new_len(t_list *list, int new_data)
{
	int	len;
	int	i;

	len = list->len + new_data;
	i = 0;
	while (i++ < len)
	{
		list->len = len;
		list = list->next;
	}
}

t_list	*ft_list_at(t_list *list, int data)
{
	int		i;
	t_list	*list_current;

	list_current = list;
	i = 0;
	while (i < list->len)
	{
		if (list_current->data == data)
			return (list_current);
		list_current = list_current->next;
		i++;
	}
	return (NULL);
}

void	ft_listclear(t_list **list)
{
	t_list	*newlist;
	int		nbdata;
	int		i;

	if (!(*list))
		return ;
	nbdata = (*list)->len;
	i = 0;
	while (i < nbdata)
	{
		newlist = *list;
		*list = (*list)->next;
		if (newlist)
		{
			free(newlist);
			newlist = NULL;
		}
		i++;
	}
}
