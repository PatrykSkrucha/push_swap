/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:53 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 18:50:17 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	check_if_sorted(t_single *stack)
{
	while (stack && stack->next)
	{
		if (stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	precheck(char *str)
{
	int	i;

	if (!better_strlen(str))
	{
		return (1);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
		{
			return (1);
		}
	}
	if (ft_atoi(str) != ft_atoi_long(str))
		return (1);
	return (0);
}

int	check_duplicte(t_single *stack)
{
	t_single	*head;
	int			temp;

	while (stack && stack->next)
	{
		head = stack;
		temp = stack->number;
		stack = stack->next;
		while (stack)
		{
			if (temp == stack->number)
				return (1);
			stack = stack->next;
		}
		stack = head->next;
	}
	return (0);
}

void	after_checks(t_two *stack)
{
	if (check_duplicte(stack->stack_a) && !free_stacks(stack))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (!check_if_sorted(stack->stack_a) && !free_stacks(stack))
		exit (EXIT_SUCCESS);
}

int	check_and_appent(char **str, t_two *stack)
{
	int		j;

	j = -1;
	while (str[++j])
	{
		if (precheck(str[j]))
			return (1);
		if (add_back(stack, new_list(ft_atoi(str[j])), 1))
			return (1);
	}
	return (0);
}
