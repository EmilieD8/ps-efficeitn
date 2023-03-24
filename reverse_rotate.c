/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:24 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:08:25 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate_up(t_list **stack)
{
	t_list  *tmp;
    t_list  *head;

    tmp = get_tail(*stack);
	head = *stack;
	while (head->next->next != NULL)
		head = head->next;
	head->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void reverse_rotate_a (t_list **stack_a)
{
	rotate_up(stack_a);
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void reverse_rotate_b (t_list **stack_b)
{
	rotate_up(stack_b);
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void reverse_rotate_rr (t_list **stack_a, t_list **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
