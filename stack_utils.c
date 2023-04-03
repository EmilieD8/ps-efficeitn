/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:53:48 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/31 17:53:49 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_element_stack(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	return (new);
}

t_list	*get_tail(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_stack_back(t_list **stack, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_tail(*stack);
	tail->next = new;
}

void	add_stack_front(t_list **stack, t_list *new)
{
	t_list	*head;

	head = *stack;
	if (!head)
		return ;
	new->next = *stack;
}
