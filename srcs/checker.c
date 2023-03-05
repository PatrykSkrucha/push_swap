/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:34:41 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/05 00:26:40 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap_bonus.h"

int	is_correct(t_two *stack)
{
	if (lstsize(stack->stack_b) > 0)
		return (0);
	while (stack->stack_a->next)
	{
		if (stack->stack_a->number > stack->stack_a->next->number)
			return (0);
		stack->stack_a = stack->stack_a->next;
	}
	return (1);
}

void	perform_action(char *input, int *control, t_two *stack)
{
	//ft_printf("hello");
	if (ft_strlen(input) == 3 && !ft_strncmp(input, "sa\n", 3))
		sa(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "sb\n", 3))
		sb(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "ss\n", 3))
	{
		sa(stack);
		sb(stack);
	}
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "pa\n", 3))
		push_a(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "pb\n", 3))
		push_b(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "ra\n", 3))
		move_backwards_a(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rb\n", 3))
		move_backwards_b(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rr\n", 3))
	{
		move_backwards_a(stack);
		move_backwards_b(stack);
	}
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rra\n", 3))
		move_forward_a(stack);
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrb\n", 3))
		move_forward_b(stack);
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrr\n", 3))
	{
		move_forward_a(stack);
		move_forward_a(stack);
	}
	else
	{
		ft_printf("input: %s", input);
		*control = 0;
	}
}

int main(int argc, char **argv)
{
	char	*input = "";

	size_t	amount;
	t_two	*stack;
	int		valid_command;

	amount = 1;

	valid_command = 1;
	stack = arrange_stack(argv, argc);
	while (amount > 0 && valid_command)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		perform_action(input, &valid_command, stack);
		free(input);
	}
	if (!is_correct(stack) || !valid_command)
		ft_printf("Error\n");
	return (0);
}