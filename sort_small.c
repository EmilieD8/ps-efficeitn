/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:43 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 12:54:36 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_bis(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		rotate_a(stack);
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		swap_a(stack);
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content
		&& (*stack)->content < (*stack)->next->next->content)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

void	sort_three(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		reverse_rotate_a(stack);
		if (is_sorted(stack) == 1)
			return ;
		swap_a(stack);
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content
		&& (*stack)->content > (*stack)->next->next->content)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else
		sort_three_bis(stack);
}

void	sort_two(t_list **stack)
{
	if (is_sorted(stack) == 1)
		return ;
	else
		swap_a(stack);
}

void	rotate_b_to_a(t_list **stack_b, int position)
{
	int	size;
	int	number;

	size = size_stack(*stack_b);
	if ((size - position + 1) <= (position - 1))
	{
		number = size - position + 1;
		while (number > 0)
		{
			reverse_rotate_b(stack_b);
			number--;
		}
	}	
	else
	{
		number = position - 1;
		while (number > 0)
		{
			rotate_b(stack_b);
			number--;
		}
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b, int argc)
{
	int	position;
	int	number;

	number = 1;
	while (argc > 3)
	{
		assign_position(stack_a);
		position = find_position_small(stack_a, number);
		rotate_b_to_a(stack_b, position);
		push_b(stack_a, stack_b);
		number++;
		argc--;
	}
	sort_three(stack_a);
	while (size_stack(*stack_b) > 0)
		push_a(stack_b, stack_a);
}
