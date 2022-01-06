/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:31:13 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/27 00:26:11 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*tmp;

	if ((*stack)->len <= 1)
		return ;
	tmp = (*stack)->next;
	(*stack)->prev->next = tmp;
	tmp->prev = (*stack)->prev;
	(*stack)->next = (*stack)->next->next;
	(*stack)->next->next->prev = (*stack);
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	(*stack) = tmp;
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
}

void	push_swaperoo(t_list **stack_two, t_list **prev_tmp)
{
	if ((*stack_two)->len == 1)
		*stack_two = NULL;
	else
	{
		*prev_tmp = (*stack_two)->prev;
		(*stack_two)->prev->next = (*stack_two)->next;
		*stack_two = (*stack_two)->next;
		(*stack_two)->prev = *prev_tmp;
		new_len(*stack_two, -1);
	}
}

void	pushfive(t_list **receive, t_list **send, char c)
{
	t_list	*tmp;
	t_list	*prev_tmp;

	if (!(*send))
		return ;
	tmp = *send;
	push_swaperoo(send, &prev_tmp);
	if (!(*receive))
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		tmp->len = 1;
		*receive = tmp;
	}
	else
		ft_list_pfront(receive, tmp);
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}

void	push(t_list **receive, t_list **send, char c)
{
	t_list	*tmp;
	t_list	*prev_tmp;

	if (!(*send))
		return ;
	tmp = *send;
	push_swaperoo(send, &prev_tmp);
	if (!(*receive))
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		tmp->len = 1;
		*receive = tmp;
	}
	else
		ft_list_push_front(receive, tmp);
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}
