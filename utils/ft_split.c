/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:41:19 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/22 16:23:40 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	n_words(char c, const char *str)
{
	int	i;
	int	check;
	int	n;

	i = 0;
	check = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != c && check == 0)
		{
			check = 1;
			n++;
		}
		else if (str[i] == c)
			check = 0;
		i++;
	}
	return (n);
}

char	*copy_word(const char *str, int begin, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - begin + 1));
	while (begin < end)
	{
		word[i] = str[begin];
		i++;
		begin++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = (char **)malloc(sizeof(char *) * n_words(c, str) + 1);
	if (!str || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = copy_word(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
