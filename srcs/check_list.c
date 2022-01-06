/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:02:04 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/22 16:39:06 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = list->len;
	while (i < len - 1)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int	check_limit_int(char *str)
{
	long long	tmp;

	tmp = ft_strtol(str);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (1);
	return (0);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
		i++;
	if (i > 0 && !str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(char **arg)
{
	int	i;

	i = 0;
	if (ft_double(arg))
		return (1);
	while (arg[i])
	{
		if (check_limit_int(arg[i]) || ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_double(char **arg)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (arg[len])
		len++;
	if (len < 2)
		return (0);
	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (!ft_strcmp(arg[i], arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
