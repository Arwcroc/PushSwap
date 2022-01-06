/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:24:39 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/06 18:08:46 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **list, char c)
{
	if ((*list)->len <= 1)
		return ;
	*list = (*list)->prev;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	r_rotate_r(t_list *lista, t_list *listb)
{
	r_rotate(&lista, 'x');
	r_rotate(&listb, 'x');
	write(1, "rrr\n", 4);
}

void	rotate(t_list **list, char c)
{
	if ((*list)->len <= 1)
		return ;
	*list = (*list)->next;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rotate_r(t_list *lista, t_list *listb)
{
	r_rotate(&lista, 'x');
	r_rotate(&listb, 'x');
	write(1, "rr\n", 3);
}
