/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:44:26 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/06 17:24:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				index_data;
	int				len;
}					t_list;

t_list		*list_init(char **list, int len);
void		set_index(t_list *list);
void		new_len(t_list *list, int new_data);
t_list		*ft_list_at(t_list *list, int data);
void		ft_listclear(t_list **list);

void		ft_list_push_front(t_list **begin_list, t_list *newlist);
void		ft_list_pfront(t_list **begin_list, t_list *newlist);
void		ft_list_pushback(t_list *begin_list, int data, int i);

void		r_rotate(t_list **stack, char c);
void		r_rotate_r(t_list *lista, t_list *listb);
void		rotate(t_list **stack, char c);
void		rotate_r(t_list *lista, t_list *listb);

void		swap(t_list **stack, char c);
void		push_swaperoo(t_list **stack_two, t_list **prev_tmp);
void		pushfive(t_list **receive, t_list **send, char c);
void		push(t_list **receive, t_list **send, char c);

int			check_sort(t_list *list);
int			check_limit_int(char *str);
int			ft_isdigit(char *str);
int			check_arg(char **arg, int ac);
int			ft_double(char **arg);

void		sort_stack(t_list **lista, t_list **listb);
int			maxbits_possible(t_list *list);
void		ft_five(t_list **lista, t_list **listb);
void		ft_three(t_list **list, char c);

int			get_lowest(t_list *a);
int			get_highest(t_list *b);
void		which_sort(t_list **lista, t_list **listb, int size);

char		**ft_split(char const *str, char c);
int			ft_freee(char **tab);

char		**ft_get_argv(int ac, char **av);
int			ft_strcmp(char *s1, char *s2);
int			ft_strtoi(char *str);
long long	ft_strtol(char *str);

#endif
