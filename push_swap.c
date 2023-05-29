/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:35:44 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/14 13:37:22 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	if (!is_correct_input(argv))
	{
		write(2, "Error\n", 6);
		return(0);
	}
	if (argc < 3)
		return (0);
	list_a = NULL;
	list_b = NULL;
	list_a = fill_list_a(list_a, argv);
	if(is_organized(list_a, list_b))
		return (0);
	sort(argc, &list_a, &list_b);
	free_stack(&list_a);
	free_stack(&list_b);
	return (0);
}
