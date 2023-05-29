/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:38:58 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 15:38:58 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
