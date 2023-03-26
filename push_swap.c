/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:07 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/26 18:58:13 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list **stack_b, int top, int bottom, int quarter)
{
	t_list *tmp;
	int position;
	top = top - 1;
	
		tmp = *stack_b;
		while (tmp != NULL)
		{
			if (tmp->index == top || (tmp->index > bottom && tmp->index > quarter))
			{
				position = tmp->position;
				break;
			}
			tmp = tmp->next;
		}
	return(position);
}

void	rotate_push(t_list **stack_a, t_list **stack_b, int position)
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
	push_a(stack_b, stack_a);
}
int	division(int size)
{
	int divide;

	if (size <= 100)
		return (10);
	else if (size <= 500)
		return (20);
	return (0);
}
void	push_chunks(t_list **stack_a, t_list **stack_b, int size)
{
	t_list **tmp;
	int percentage;
	int loop;

	tmp = stack_a;
	percentage = size / division(size);
	loop = size / (division(size) / 2);
	while (size_stack(*stack_a) > 0)
	{
		while(loop > 0)
		{
			if ((*tmp)->index >= (size - percentage))// 90 - 100
			{
				push_b(stack_a, stack_b);
				tmp = stack_a;
				loop--;
			}
			else if ((*tmp)->index <= percentage)
			{
				push_b(stack_a, stack_b);
				rotate_b(stack_b);
				tmp = stack_a;
				loop--;
			}
			else
				rotate_a(stack_a);
		}
		percentage = percentage + size / division(size); 
		if (size_stack(*stack_a) < size / (division(size) / 2))
			loop = size_stack(*stack_a);
		else
			loop = size / (division(size) / 2);
	}	
	while(get_tail(*stack_b)->index != size)
		rotate_b(stack_b);
}

void order_back (t_list **stack_a, t_list **stack_b)
{
	t_list **tmp;
	t_list **head;
	int position;
	int top;
	int quarter;
	
	quarter = size_stack(*stack_b) - 10;
	reverse_rotate_b(stack_b);
	push_a(stack_b, stack_a);
	// push_a(stack_b, stack_a);
	// // print_stack(stack_a);
	// rotate_a(stack_a); // put biggest index in the stack a 
	while (size_stack(*stack_b) > 0)
	{
		tmp = stack_b;
		head = stack_a;
		assign_position(tmp);
		position = find_position(tmp, (*head)->index, (get_tail(*stack_a)->index), quarter);
		rotate_push(stack_a, tmp, position); 
		head = stack_a;
		if ((*head)->index != (*head)->next->index - 1 && size_stack(*stack_a) > 1)
			rotate_a(stack_a);
		if (get_tail(*stack_a)-> index == (*head)->index -1 && size_stack(*stack_a) > 1)
			reverse_rotate_a(stack_a);  //  double ?
		// if (get_tail(*stack_a)->index == (*head)->index -1)
		// {	
		// 	reverse_rotate_a(stack_a);
		// 	head = stack_a;
		// }
		// tmp = stack_b;
		quarter--;
	}
	// push_a(stack_b, stack_a); necessarry ?
}

int main(int argc, char** argv)
{
    t_list *stack_a;
    t_list *stack_b;
	int quarter;

	if (argc < 2)
		return (0);
	
    stack_a = fill_stack(argc, argv);
    stack_b = NULL;

	// if (argc == 3)
	// 	sort_two(&stack_a);
	// if (argc == 4)
	// 	sort_three(&stack_a);
	// else
	// {
	assign_index(&stack_a);
	push_chunks(&stack_a, &stack_b, argc - 1);
	// print_stack(&stack_b);
	// printf("SIZE IS %d", size_stack(stack_b));
	order_back(&stack_a, &stack_b);
	// // }
	// push_a(&stack_b, &stack_a);
	
	// print_stack(&stack_a);
	// print_stack(&stack_b);

	// printf("\n\n");

}