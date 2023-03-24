/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:13 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/20 16:25:56 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

//# include "ft_printf/ft_printf.h"

typedef struct s_list
{
    int content;
    struct s_list *next;
    int  position;
    int index;
}   t_list;

void swap_swap (t_list **stack_a, t_list **stack_b);
void swap_a (t_list **stack_a);
void swap_b (t_list **stack_b);
void print_stack (t_list **stack);
void add_stack_front(t_list **stack, t_list *new);
void add_stack_back(t_list **stack, t_list *new);
t_list *get_tail(t_list *stack);
t_list *new_element_stack(int value);
void rotate_a (t_list **stack_a);
void rotate_b (t_list **stack_b);
void rotate_rr (t_list **stack_a, t_list **stack_b);
void reverse_rotate_a (t_list **stack_a);
void reverse_rotate_b (t_list **stack_b);
void reverse_rotate_rr (t_list **stack_a, t_list **stack_b);
void push_a (t_list **stack_b, t_list **stack_a);
void push_b (t_list **stack_a, t_list **stack_b);
int	ft_atoi(const char *nptr);
t_list *fill_stack(int argc, char** argv);
int size_stack (t_list *stack);
void copy_stack (t_list *temp, t_list *stack);
int	is_sorted (t_list **stack);
void assign_base_index (t_list **stack);
void assign_highest_index (t_list **stack, int i, int index) ;
int next_highest(t_list **stack, int index);
void assign_index (t_list **stack);
void sort_three (t_list **stack);
void sort_two (t_list **stack);
void assign_position (t_list **stack);
int	is_sorted_reverse (t_list **stack);

#endif
