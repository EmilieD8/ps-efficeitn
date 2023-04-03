/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:07 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 11:32:05 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc <= 5)
	{
		assign_index(stack_a);
		sort_five(stack_a, stack_b, argc - 1);
	}
	else
	{
		assign_index(stack_a);
		push_chunks(stack_a, stack_b, argc - 1);
		order_back(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	if (check_input(&stack_a) == 0)
		return (0);
	if (argc < 2)
		return (0);
	else
		push_swap(&stack_a, &stack_b, argc);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
