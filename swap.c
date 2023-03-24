/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:59 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:09:00 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap (t_list **stack)  
{
	int tmp;
	if (size_stack(*stack) <= 1)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;

}

void swap_swap (t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss", 2);
	write(1, "\n", 1);
}

void swap_a (t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void swap_b (t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb", 2);
	write(1, "\n", 1);
}
