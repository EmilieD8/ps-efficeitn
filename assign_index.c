/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:07:15 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:07:16 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_base_index(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}	
}

void	assign_highest_index(t_list **stack, int i, int index)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->content == i && tmp->index == -1)
		{
			tmp->index = index;
			break ;
		}
		tmp = tmp->next;
	}
}

int	next_highest(t_list **stack, int index)
{
	t_list	*tmp;
	int		i;

	i = -1;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->content > i && tmp->content < INT_MAX && tmp->index == -1)
			i = tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

void	assign_index(t_list **stack)
{
	int	index;
	int	i;

	index = size_stack(*stack);
	assign_base_index(stack);
	while (index > 0)
	{
		i = next_highest(stack, index);
		assign_highest_index(stack, i, index);
		index--;
	}
}
