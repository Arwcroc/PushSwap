/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:17:49 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/22 16:42:08 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lowest(t_list *a)
{
	int	lowest;
	int	i;

	lowest = a->data;
	i = 0;
	while (i < a->len)
	{
		if (a->data < lowest)
			lowest = a->data;
		a = a->next;
		i++;
	}
	return (lowest);
}

int	get_highest(t_list *b)
{
	int	i;
	int	highest;

	i = 0;
	highest = b->data;
	while (i < b->len)
	{
		if (b->data > highest)
			highest = b->data;
		b = b->next;
		i++;
	}
	return (highest);
}

void	which_sort(t_list **lista, t_list **listb, int len)
{
	if (!check_sort(*lista))
	{
		set_index(*lista);
		if (len == 2)
			rotate(lista, 'a');
		else if (len == 3)
			ft_three(lista, 'a');
		else if (len <= 5)
			ft_five(lista, listb);
		else
			sort_stack(lista, listb);
	}
}

/*
	// for (int i = 0; i < lista->len; i++)
	// {
	// 	printf("%d\n", lista->data);
	// 	lista = lista->next;
	// }
*/
int	main(int ac, char **av)
{
	t_list	*lista;
	t_list	*listb;
	char	**arg;
	int		i;

	if (ac <= 1 || av[1] == NULL)
		exit (EXIT_FAILURE);
	arg = ft_get_argv(ac, av);
	if (!(*arg) || !(**arg))
		exit (EXIT_FAILURE);
	else if (check_arg(arg))
	{
		fprintf(stderr, "ERROR\n");
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (arg[i])
		i++;
	lista = list_init(arg, i);
	listb = NULL;
	which_sort(&lista, &listb, i);
	ft_listclear(&lista);
	ft_listclear(&listb);
	exit (EXIT_SUCCESS);
}
