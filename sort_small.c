/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:43 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:08:44 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void sort_three (t_list **stack)
{

	if ((*stack)->content < (*stack)->next->content && (*stack)->next->content > (*stack)->next->next->content  && (*stack)->content > (*stack)->next->next->content)
	{
		reverse_rotate_a(stack);
		if (is_sorted(stack) == 1)
			return ;
		swap_a(stack);
	}
	else if ((*stack)->content > (*stack)->next->content && (*stack)->next->content > (*stack)->next->next->content && (*stack)->content > (*stack)->next->next->content)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if ((*stack)->content > (*stack)->next->content && (*stack)->next->content < (*stack)->next->next->content && (*stack)->content > (*stack)->next->next->content)
		rotate_a(stack);
	else if ((*stack)->content > (*stack)->next->content && (*stack)->next->content < (*stack)->next->next->content && (*stack)->content < (*stack)->next->next->content)
		swap_a(stack);
	else if ((*stack)->content < (*stack)->next->content && (*stack)->next->content > (*stack)->next->next->content  && (*stack)->content < (*stack)->next->next->content)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

void sort_two (t_list **stack)
{
	if (is_sorted(stack) == 1)
		return ;
	else
		swap_a(stack);
}
