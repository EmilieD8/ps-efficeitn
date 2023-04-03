/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:31 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/23 13:20:00 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_down(t_list **stack)
{
	t_list	*temp;
	t_list	*tail;

	if (size_stack(*stack) == 1 || size_stack(*stack) == 0)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = get_tail(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	rotate_a(t_list **stack_a)
{
	rotate_down(stack_a);
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rotate_b(t_list **stack_b)
{
	rotate_down(stack_b);
	write(1, "rb", 2);
	write(1, "\n", 1);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rr", 2);
	write(1, "\n", 1);
}
