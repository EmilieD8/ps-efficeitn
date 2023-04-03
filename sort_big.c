/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:39:42 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 13:01:09 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_b(t_list **stack_b, int position)
{
	int		size;
	int		number;

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

double	division(int size)
{
	double	divide;
	
	divide = 2;
	if (size <= 50)
		return (2);
	else if (size <= 300)
		divide = size * 0.12;
	else if (size > 300)
		divide = size * 0.06;
	return (divide);
}

int	number_in_stack(t_list *stack_a, int percentage, int size)
{
	int	first;
	int	last;

	last = size - percentage;
	first = percentage;
	while (stack_a != NULL)
	{
		if (stack_a->index <= first || stack_a->index >= last)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	push_chunks(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	**tmp;
	int		percentage;

	tmp = stack_a;
	percentage = division(size);
	while (size_stack(*stack_a) > 0)
	{
		while (number_in_stack(*stack_a, percentage, size) == 1)
		{
			tmp = stack_a;
			if ((*tmp)->index >= (size - percentage))
				push_b(stack_a, stack_b);
			else if ((*tmp)->index <= percentage)
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
			}
			else
				rotate_a(stack_a);
		}
		percentage = percentage + division(size);
	}	
	while (get_tail(*stack_b)->index != size)
		rotate_b(stack_b);
}

void	order_back(t_list **stack_a, t_list **stack_b)
{
	t_list	**tmp;
	t_list	**head;
	int		pos;

	reverse_rotate_b(stack_b);
	push_a(stack_b, stack_a);
	while (size_stack(*stack_b) > 0)
	{
		tmp = stack_b;
		head = stack_a;
		assign_position(tmp);
		pos = find_position(tmp, (*head)->index, (get_tail(*stack_a)->index));
		rotate_a_to_b(tmp, pos);
		push_a(stack_b, stack_a);
		head = stack_a;
		if ((*head)->index != (*head)->next->index - 1
			&& size_stack(*stack_a) > 1)
			rotate_a(stack_a);
		else if (get_tail(*stack_a)-> index == (*head)->index -1
			&& size_stack(*stack_a) > 1)
			reverse_rotate_a(stack_a);
	}
}
