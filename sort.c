/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:59:34 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/24 16:59:34 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_media_number(t_list **list_a, t_list **list_b)
{
	int	numb;
	int	op;

	numb = find_media_number(*list_a, 10000);
	op = get_op(*list_a, numb);
	if (op < 0)
	{
		op *= -1;
		run_function(do_ra, list_a, list_b, op);
	}
	else
		run_function(do_rra, list_a, list_b, op);
	do_pb(list_a, list_b);
}

void	sort_last_b(t_list **list_a, t_list **list_b, int moves_a, int moves_b)
{
	int		total_moves;
	int		moves_a_tmp;
	int		moves_b_tmp;
	int		tmp_vis;
	t_list	*tmp_b;

	tmp_b = *list_b;
	total_moves = 1000;
	while (tmp_b)
	{
		moves_b_tmp = get_op(*list_b, tmp_b->index);
		tmp_vis = find_vis(*list_a, tmp_b->index);
		moves_a_tmp = get_op(*list_a, tmp_vis);
		if (total_moves > get_positive(moves_a_tmp) + get_positive(moves_b_tmp))
		{
			total_moves = get_positive(moves_a_tmp) + get_positive(moves_b_tmp);
			moves_a = moves_a_tmp;
			moves_b = moves_b_tmp;
		}
		tmp_b = tmp_b->next;
	}
	make_moves(list_a, list_b, moves_a, moves_b);
}

static void	sort_3(t_list **list_a, t_list **list_b)
{
	give_tmp(list_a);
	if ((*list_a)->tmp == 1)
		no_norm(list_a, list_b);
	else if ((*list_a)->tmp == 2)
	{
		if ((*list_a)->next->tmp == 1)
		{
			do_sa(list_a, list_b);
			do_rra(list_a, list_b);
		}
		else if ((*list_a)->next->tmp == 0)
			do_ra(list_a, list_b);
	}
	else if ((*list_a)->tmp == 0)
	{
		if ((*list_a)->next->tmp == 2)
		{
			do_sa(list_a, list_b);
			do_ra(list_a, list_b);
		}
	}
}

static void	sort_max(t_list **list_a, t_list **list_b)
{
	int	op;

	while (get_stack_len(*list_a) != 3)
		sort_media_number(list_a, list_b);
	sort_3(list_a, list_b);
	while (get_stack_len(*list_b) != 0)
		sort_last_b(list_a, list_b, 0, 0);
	op = get_op(*list_a, find_smallest_numb(*list_a));
	if (op < 0)
		run_function(do_ra, list_a, list_b, -op);
	else if (op != 0)
		run_function(do_rra, list_a, list_b, op);
}

void	sort(int argc, t_list **list_a, t_list **list_b)
{
	if (argc < 5)
		sort_3(list_a, list_b);
	else
		sort_max(list_a, list_b);
}
