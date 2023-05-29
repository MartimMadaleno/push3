/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmendes- <mmendes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:27:59 by mmendes-          #+#    #+#             */
/*   Updated: 2023/02/14 13:29:35 by mmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				tmp;
	struct s_list	*next;
}	t_list;

typedef void	(*t_func_ptr)(t_list**, t_list**);
void		sort(int argc, t_list **list_a, t_list **list_b);
t_list		*fill_list_a(t_list *list_a, char **argv);
int			is_correct_input(char **argv);
t_list		*ft_lstnew(int value, int index);
void		ft_lstadd_back(t_list *lst, t_list *new);
int			ft_isdigit(int arg);
void		*ft_calloc(size_t nitems, size_t size);
void		ft_bzero(void *s, size_t n);
long int	ft_atoi(const char *str);
void		print_list(t_list *head);
t_list		*get_stack_bottom(t_list *stack);
t_list		*get_stack_before_bottom(t_list *stack);
void		run_function(t_func_ptr func, t_list **stack_a,
				t_list **stack_b, int times);
int			find_smallest_numb(t_list *lst);
int			find_vis(t_list *lst, int numb);
int			find_media_number(t_list *lst, int new_op);
int			count_numb_op(t_list *lst, int numb);
int			get_positive(int num);
long int	get_media(t_list *lst);
int			get_stack_len(t_list *lst);
int			get_op(t_list *lst, int numb);
int			is_organized(t_list *list_a, t_list *list_b);
void		sort_last_b(t_list **list_a, t_list **list_b,
				int moves_a, int moves_b);
void		make_moves(t_list **list_a, t_list **list_b,
				int moves_a, int moves_b);
void		no_norm(t_list **list_a, t_list **list_b);
void		free_stack(t_list **stack);
void		give_tmp(t_list **list_a);
void		do_pa(t_list **stack_a, t_list **stack_b);
void		do_pb(t_list **stack_a, t_list **stack_b);
void		do_sa(t_list **stack_a, t_list **stack_b);
void		do_sb(t_list **stack_a, t_list **stack_b);
void		do_ss(t_list **stack_a, t_list **stack_b);
void		do_ra(t_list **stack_a, t_list **stack_b);
void		do_rb(t_list **stack_a, t_list **stack_b);
void		do_rr(t_list **stack_a, t_list **stack_b);
void		do_rra(t_list **stack_a, t_list **stack_b);
void		do_rrb(t_list **stack_a, t_list **stack_b);
void		do_rrr(t_list **stack_a, t_list **stack_b);

#endif