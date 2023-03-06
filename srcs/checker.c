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

int	is_sorted(t_single *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}



void	perform_action(char *input, int *control, t_two *stack)
{
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
		pa(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "pb\n", 3))
		pb(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "ra\n", 3))
		ra(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rb\n", 3))
		rb(stack);
	else if (ft_strlen(input) == 3 && !ft_strncmp(input, "rr\n", 3))
	{
		ra(stack);
		rb(stack);
	}
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rra\n", 3))
		rra(stack);
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrb\n", 3))
		rrb(stack);
	else if (ft_strlen(input) == 4 && !ft_strncmp(input, "rrr\n", 3))
	{
		rra(stack);
		rrb(stack);
	}
	else
		*control = 0;
}

int main(int argc, char **argv)
{
	char	*input = "";
	size_t	amount;
	t_two	*stack;
	int		valid_command;

	if (argc < 2)
		return (0);
	if ((check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc)) && ft_printf("Error\n"))
		return (255);
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
	if (!valid_command)
	{
		ft_printf("Error\n");
		return (255);
	}
	if (is_sorted(stack->stack_a) && lstsize(stack->stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}