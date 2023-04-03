/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:07:22 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 11:21:08 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

t_list	*fill_stack(int argc, char **argv)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			write(1, "Error\n", 6);
			free_stack(&stack_a);
			return (stack_a);
		}
		if (i == 1)
			stack_a = new_element_stack((int)nb);
		else
			add_stack_back(&stack_a, new_element_stack((int)nb));
		i++;
	}
	return (stack_a);
}

int	size_stack(t_list *stack)
{
	t_list	*tmp;
	int		size;

	if (stack == NULL)
		return (0);
	tmp = stack;
	size = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	copy_stack(t_list *temp, t_list *stack)
{
	while (stack->next != NULL)
	{
		temp->content = stack->content;
		temp = temp->next;
		stack = stack->next;
	}
}
