/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_n_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:22:05 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/22 16:22:38 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_strtol(char *str)
{
	int			i;
	long long	result;
	int			neg;

	i = 0;
	result = 0;
	neg = 0;
	if (str[i] == '-')
	{
		i++;
		neg = 1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg)
		result = result * -1;
	return (result);
}

int	ft_strtoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 0;
	result = 0;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg)
		result = result * -1;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while ((*s1 || *s2) && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		return (((unsigned char)*s1 - (unsigned char)(*s2)));
	}
	return (0);
}

char	**ft_get_argv(int ac, char **av)
{
	char	**i;

	i = av + 1;
	if (ac < 2)
		return (NULL);
	else if (ac == 2)
		i = ft_split(av[1], ' ');
	return (i);
}
