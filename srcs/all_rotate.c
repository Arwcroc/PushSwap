/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 00:24:39 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/27 00:24:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_rotate(t_list **list, char c)
{
	if ((*list)->len <= 1)
		return ;
	*list = (*list)->prev;
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
}

void	r_rotate_r(t_list *lista, t_list *listb)
{
	r_rotate(&lista, 'x');
	r_rotate(&listb, 'x');
	printf("rrr\n");
}

void	rotate(t_list **list, char c)
{
	if ((*list)->len <= 1)
		return ;
	*list = (*list)->next;
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
}

void	rotate_r(t_list *lista, t_list *listb)
{
	r_rotate(&lista, 'x');
	r_rotate(&listb, 'x');
	printf("rr\n");
}
