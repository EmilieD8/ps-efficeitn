/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:07:29 by edrouot           #+#    #+#             */
/*   Updated: 2023/04/03 11:31:09 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *n)
{
	int			i;
	long int	result;
	long int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (n[i] == '\t' || n[i] == '\n' || n[i] == '\v'
		|| n[i] == '\f' || n[i] == '\r' || n[i] == ' ')
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i++] == '-')
			sign = -1;
		else if (n[i] == '+' && (n[i + 1] == '-' || n[i + 1] == '+'))
			return (2147483649);
	}
	while (n[i] != '\0' && n[i] >= '0' && n[i] <= '9')
	{
		result = result * 10 + (n[i] - 48);
		if (n[i + 1] == '-' || n[i + 1] == '+')
			return (2147483649);
		i++;
	}
	return ((sign * result));
}

int	check_input(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	head = *stack_a;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->content == tmp->content)
			{
				free_stack(stack_a);
				write(1, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}
