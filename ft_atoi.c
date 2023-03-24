/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:07:29 by edrouot           #+#    #+#             */
/*   Updated: 2023/03/18 15:07:31 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	index = 0;
	while (nptr[index] == '\t' || nptr[index] == '\n' || nptr[index] == '\v'
		|| nptr[index] == '\f' || nptr[index] == '\r' || nptr[index] == ' ')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index++] == '-')
			sign = -1;
		else if (nptr[index] == '+' && (nptr[index + 1] == '-'
				|| nptr[index + 1] == '+'))
			return (0);
	}
	while (nptr[index] != '\0' && nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - 48);
		index++;
	}
	return ((int)(sign * result));
}

