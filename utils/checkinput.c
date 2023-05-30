/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:13:07 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/23 14:13:07 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	checkdoubles(char **argv, int i)
{
	long int	num;

	num = ft_atoi(argv[i]);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) == num)
			return (0);
	}
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	h;

	i = 0;
	h = -1;
	while (argv[++i])
	{
		h = -1;
		if (argv[i][0] == '-' || argv[i][0] == '+')
				h++;
		if(!argv[i][h + 1])
			return (0);
		while (argv[i][++h])
		{
			if (!ft_isdigit(argv[i][h]))
				return (0);
		}
		if (!checkdoubles(argv, i))
			return (0);
	}
	return (1);
}

int is_organized(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

	tmp = list_a;
	while (tmp->next)
	{
		if (tmp->index + 1 != tmp->next->index)
			return(0);
		tmp = tmp->next;
	}
	free_stack(&list_a);
	free_stack(&list_b);
	return (1);
}