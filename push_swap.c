/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:07 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/23 14:19:19 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* first, push to b the 10th and 90th percentile : if 10th percentile, push and rotate, if 90th, just push
then rotate the stack to have the 90th percentile on top
push the biggest number 
push the next one : on top if the next index, in the bottom (pa ra) if not
then next one need to be either bigger than the bottom one or the next index of the top one 
rotate stack and calculate cost 
*/

// int	find_position(t_list **stack_b, int quarter)
// {
// 	t_list *tmp;
// 	int position; 
	
// 		tmp = *stack_b;
// 		while (tmp != NULL)
// 		{
// 			if (tmp->index == quarter)
// 			{
// 				position = tmp->position;
// 				break;
// 			}
// 			tmp = tmp->next;
// 		}
// 	return(position);
// }

// void	sort_quarter(t_list **stack_a, t_list **stack_b, int quarter)
// {
// 	int		size;
// 	int 	position;
// 	int		number;

// 	while (size_stack(*stack_b) > 0)
// 	{
// 		size = size_stack(*stack_b);
// 		if (is_sorted_reverse(stack_b) == 1)
// 		{	
// 			while (size_stack(*stack_b) > 0)
// 					push_a(stack_b, stack_a);
// 			break;
// 		}
// 		assign_position(stack_b);
// 		position = find_position(stack_b, quarter);
// 		if ((size - position + 1) >= (position - 1))
// 		{
// 			number = size - position + 1;
// 			while (number > 0)
// 			{
// 				reverse_rotate_b(stack_b);
// 				number--;
// 			}
// 		}	
// 		else
// 		{
// 			number = position - 1;
// 			while (number > 0)
// 			{
// 				rotate_b(stack_b);
// 				number--;
// 			}
// 		}
// 		push_a(stack_b, stack_a);
// 		quarter--;	
// 	}
// 	size--;
// }

// void push_sort_pushback(t_list **stack_a, t_list **stack_b, int size)
// {
// 	double num_quarters;
// 	int quarter_up;
// 	int quarter_down;
// 	int quarter_cpy;

// 	num_quarters = 0.25;
// 	quarter_down = 0;
// 	while (num_quarters <= 1)
// 	{
// 		quarter_up = size * num_quarters;
// 		push_quarters(stack_a, stack_b, quarter_down, quarter_up);
// 		while (get_tail(*stack_a)->index != quarter_down && quarter_down != 0)
// 			rotate_a(stack_a);
// 		sort_quarter(stack_a, stack_b, quarter_up);
// 		quarter_cpy = quarter_up - quarter_down;
// 		while (quarter_cpy > 0)
// 		{
// 			rotate_a(stack_a);
// 			quarter_cpy--;
// 		}
// 		num_quarters = num_quarters + 0.25;
// 		quarter_down = quarter_up;
// 	}
// 	rotate_a(stack_a);
// }

// void	push_quarters(t_list **stack_a, t_list **stack_b, int quarter_down, int quarter_up)
// {
// 	t_list **tmp;
// 	tmp = stack_a;
// 	int loop;
// 	loop = quarter_up - quarter_down;
// 	while (loop > 0)
// 	{
// 		if ((*tmp)->index <= quarter_up && (*tmp)->index > quarter_down)
// 		{
// 			push_b(stack_a, stack_b);
// 			tmp = stack_a;
// 			loop--;
// 		}
// 		else
// 			rotate_a(stack_a);
// 	}
// }

void	push_chunks(t_list **stack_a, t_list **stack_b, int size)
{
	t_list **tmp;
	int percentage;
	int loop;

	tmp = stack_a;
	percentage = size / 10;
	loop = size / 5;
	
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
		percentage = percentage + size / 10; 
		if (size_stack(*stack_a) < (size / 5))
			loop = size_stack(*stack_a);
		else
			loop = size / 5;
	}	
	while(get_tail(*stack_b)->index != size)
		rotate_b(stack_b);
}

void order_back (t_list **stack_a, t_list **stack_b)
{
	t_list **tmp;
	t_list *head;
	int	next_index;

	write(1, "ORDER", 5);
	reverse_rotate_b(stack_b);
	push_a(stack_b, stack_a); // put biggest index in the stack a 
	tmp = stack_b;
	head = *stack_a;
	while (tmp != NULL)
	{
		next_index = (head->index) - 1;
		printf("%d\n", next_index);
		if ((*tmp)->index == next_index)
		{
			push_a(stack_b, stack_a);
			head = *stack_a;
			tmp = stack_b;
		}
		else if ((*tmp)->index < next_index)
		{
			push_a(stack_b, stack_a);
			rotate_a(stack_a);
			head = *stack_a;
			tmp = stack_b;
		}
	}

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
		order_back(&stack_a, &stack_b);
	// // }
	print_stack(&stack_a);
	print_stack(&stack_b);

	// printf("\n\n");

	// write(1, "FIN", 3);
}
