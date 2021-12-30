/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:05:53 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/22 16:40:01 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_list **lista, t_list **listb)
{
	int	i;
	int	j;
	int	size;

	size = (*lista)->len;
	i = 0;
	while (i < maxbits_possible(*lista))
	{
		j = 0;
		while (j < size)
		{
			if ((((*lista)->index_data >> i) & 1) == 1)
				rotate(lista, 'a');
			else
				push(listb, lista, 'b');
			j++;
		}
		while ((*listb))
			push(lista, listb, 'a');
		i++;
	}
}

int	maxbits_possible(t_list *list)
{
	int	i;
	int	result;

	i = list->len - 1;
	result = 0;
	while (i)
	{
		i = i / 2;
		result++;
	}
	return (result);
}

void	ft_five(t_list **lista, t_list **listb)
{
	int	min;
	int	size;

	min = get_lowest(*lista);
	size = (*lista)->len;
	while ((*lista)->data != min)
		rotate(lista, 'a');
	pushfive(listb, lista, 'b');
	min = get_lowest(*lista);
	if (size == 5)
	{
		while ((*lista)->data != min)
			rotate(lista, 'a');
		pushfive(listb, lista, 'b');
	}
	ft_three(lista, 'a');
	pushfive(lista, listb, 'a');
	if (size == 5)
		pushfive(lista, listb, 'a');
}

void	ft_three(t_list **list, char c)
{
	int	min;
	int	max;

	min = get_lowest(*list);
	max = get_highest(*list);
	if ((*list)->data == min && (*list)->next->data == max)
	{
		swap(list, c);
		rotate(list, c);
	}
	else if ((*list)->next->data == min && (*list)->prev->data == max)
		swap(list, c);
	else if ((*list)->prev->data == min && (*list)->next->data == max)
		r_rotate(list, c);
	else if ((*list)->next->data == min && (*list)->data == max)
		rotate(list, c);
	else if ((*list)->prev->data == min && (*list)->data == max)
	{
		rotate(list, c);
		swap(list, c);
	}
}
