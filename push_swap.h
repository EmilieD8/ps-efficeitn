/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:13 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 12:55:25 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
	int				position;
	int				index;
}	t_list;

void		swap_swap(t_list **stack_a, t_list **stack_b);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		add_stack_front(t_list **stack, t_list *new);
void		add_stack_back(t_list **stack, t_list *new);
t_list		*get_tail(t_list *stack);
t_list		*new_element_stack(int value);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		rotate_rr(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a(t_list **stack_a);
void		reverse_rotate_b(t_list **stack_b);
void		reverse_rotate_rr(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_b, t_list **stack_a);
void		push_b(t_list **stack_a, t_list **stack_b);
long int	ft_atoi(const char *nptr);
t_list		*fill_stack(int argc, char	**argv);
int			size_stack(t_list *stack);
void		copy_stack(t_list *temp, t_list *stack);
int			is_sorted(t_list **stack);
void		assign_base_index(t_list **stack);
void		assign_highest_index(t_list **stack, int i, int index);
int			next_highest(t_list **stack);
void		assign_index(t_list **stack);
void		sort_three(t_list **stack);
void		sort_three_bis(t_list **stack);
void		sort_two(t_list **stack);
void		assign_position(t_list **stack);
int			is_sorted_reverse(t_list **stack);
void		sort_five(t_list **stack_a, t_list **stack_b, int argc);
void		order_back(t_list **stack_a, t_list **stack_b);
void		push_chunks(t_list **stack_a, t_list **stack_b, int size);
double		division(int size);
int			find_position(t_list **stack_b, int top, int bottom);
void		free_stack(t_list **stack);
int			check_input(t_list **stack_a);
void		push_swap(t_list **stack_a, t_list **stack_b, int argc);
void		rotate_a_to_b(t_list **stack_b, int position);
int			number_in_stack(t_list *stack_a, int percentage, int size);
void		rotate_b_to_a(t_list **stack_b, int position);
int			find_position_small(t_list **stack_a, int number);

#endif
