/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:54 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 12:58:42 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content < tmp->next->content)
		{
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

int	is_sorted_reverse(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
		{
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	find_position(t_list **stack_b, int top, int bottom)
{
	t_list	*tmp;
	int		position;

	top = top - 1;
	tmp = *stack_b;
	position = 1;
	while (tmp != NULL)
	{
		if (tmp->index == top || (tmp->index > bottom))
		{
			position = tmp->position;
			break ;
		}
		tmp = tmp->next;
	}
	return (position);
}

int	find_position_small(t_list **stack_a, int number)
{
	t_list	*tmp;
	int		position;

	tmp = *stack_a;
	position = 1;
	while (tmp != NULL)
	{
		if (tmp->index == number)
		{
			position = tmp->position;
			break ;
		}
		tmp = tmp->next;
	}
	return (position);
}
