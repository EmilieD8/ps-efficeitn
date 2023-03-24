/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:54 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/20 16:24:17 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted (t_list **stack)
{
	t_list *tmp;
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

int	is_sorted_reverse (t_list **stack)
{
	t_list *tmp;
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