/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 18:04:01 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_everything(t_two *stack)
{
	t_single	*temp;

	temp = stack->stack_a;
	while (stack->stack_a)
	{
		temp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		free(temp);
	}
	while (stack->stack_b)
	{
		temp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		free(temp);
	}
	free(stack);
}

static t_two	*arrange_stack(char **input, int amount)
{
	int		i;
	t_two	*stack;

	i = 0;
	stack = (t_two *)malloc(sizeof(t_two));
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	if (!stack)
		return (NULL);
	while (++i < amount)
		add_back(stack, new_list(ft_atoi(input[i])), 1);
	set_index(stack->stack_a);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_two	*stack;

	if (check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc))
		return (write(1, "Error\n", 6));
	if (check_if_sorted(argv, argc))
		return (0);
	stack = arrange_stack(argv, argc);
	if (lstsize(stack->stack_a) == 2)
		sa(stack);
	else if (lstsize(stack->stack_a) == 3)
		sort_three(stack);
	else
		turk(stack);
	return (0);
}