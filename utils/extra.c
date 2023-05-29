/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:13:07 by mmendes-          #+#    #+#             */
/*   Updated: 2023/05/24 20:24:36 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_tmp(t_list **list_a)
{
	t_list	*tmp;
	t_list	*newtmp;

	tmp = (*list_a);
	newtmp = (*list_a);
	while (tmp)
	{
		tmp->tmp = 0;
		while (newtmp)
		{
			if (tmp->index > newtmp->index)
				tmp->tmp += 1;
			newtmp = newtmp->next;
		}
		tmp = tmp->next;
		newtmp = (*list_a);
	}
}

int	count_numb_op(t_list *lst, int numb)
{
	t_list	*tmp;
	int		count_first;
	int		count_last;

	count_first = 0;
	count_last = 0;
	tmp = lst;
	while (tmp->index != numb)
	{
		count_first++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		count_last++;
		tmp = tmp->next;
	}
	if (count_first <= count_last)
		return (count_first);
	else
		return (count_last);
}

int	get_op(t_list *lst, int numb)
{
	t_list	*tmp;
	int		count_first;
	int		count_last;

	count_first = 0;
	count_last = 0;
	tmp = lst;
	while (tmp->index != numb)
	{
		count_first++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		count_last++;
		tmp = tmp->next;
	}
	if (count_first <= count_last)
		return (-1 * count_first);
	else
		return (count_last);
}

void	make_moves(t_list **list_a, t_list **list_b, int moves_a, int moves_b)
{
	if (moves_a < 0)
		run_function(do_ra, list_a, list_b, -moves_a);
	else if (moves_a > 0)
		run_function(do_rra, list_a, list_b, moves_a);
	if (moves_b < 0)
		run_function(do_rb, list_a, list_b, -moves_b);
	else if (moves_b > 0)
		run_function(do_rrb, list_a, list_b, moves_b);
	do_pa(list_a, list_b);
}

void	no_norm(t_list **list_a, t_list **list_b)
{
	if ((*list_a)->next->tmp == 0)
		do_sa(list_a, list_b);
	else if ((*list_a)->next->tmp == 2)
		do_rra(list_a, list_b);
}
