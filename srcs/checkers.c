/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:53 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 15:15:53 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **input, int amount)
{
	int	i;
	int	j;

	i = 0;
	while (++i < amount - 1)
	{
		j = 1;
		while (j + i < amount)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[i + j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	check_if_number(char **input, int amount)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (++i < amount)
	{
		j = -1;
		len = better_strlen(input[i]);
		if (!len)
			return (1);
		while (++j < len)
		{
			if (input[i][j] == '-')
				j++;
			if (!ft_isdigit(input[i][j]))
				return (1);
		}
	}
	return (0);
}

int	check_if_sorted(char **input, int amount)
{
	int	i;

	i = 0;
	while (++i < amount - 1)
	{
		if (ft_atoi(input[i]) > ft_atoi(input[i + 1]))
			return (0);
	}
	return (1);
}

int	check_min_max(char **input, int amount)
{
	int	i;

	i = 0;
	while (++i < amount)
	{
		if (ft_atoi(input[i]) != ft_atoi_long(input[i]))
			return (1);
	}
	return (0);
}
