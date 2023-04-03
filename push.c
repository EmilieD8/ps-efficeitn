/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:07:52 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:07:53 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **stack_one, t_list **stack_two)
{
	t_list	*new;

	if (size_stack(*stack_one) == 0)
		return ;
	new = (*stack_one)->next;
	(*stack_one)->next = *stack_two;
	*stack_two = *stack_one;
	*stack_one = new;
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb", 2);
	write(1, "\n", 1);
}
