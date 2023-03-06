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

int	is_sorted_stack(t_single *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_commands(char *command)
{
	if (!ft_strncmp(command, "sa\n", 3) || !ft_strncmp(command, "sb\n", 3)
		|| !ft_strncmp(command, "ss\n", 3) || !ft_strncmp(command, "pa\n", 3)
		|| !ft_strncmp(command, "pb\n", 3) || !ft_strncmp(command, "ra\n", 3)
		|| !ft_strncmp(command, "rb\n", 3) || !ft_strncmp(command, "rr\n", 3)
		|| !ft_strncmp(command, "rra\n", 3) || !ft_strncmp(command, "rrb\n", 3)
		|| !ft_strncmp(command, "rrr\n", 3))
		return (1);
	else
		return (0);
}

void	perform_action(char *command, t_two *stack)
{
	if (!ft_strncmp(command, "sa\n", 3) && !sa(stack))
		return ;
	if (!ft_strncmp(command, "sb\n", 3) && !sb(stack))
		return ;
	if (!ft_strncmp(command, "ss\n", 3) && !sa(stack) && !sb(stack))
		return ;
	if (!ft_strncmp(command, "pa\n", 3) && !pa(stack))
		return ;
	if (!ft_strncmp(command, "pb\n", 3) && !pb(stack))
		return ;
	if (!ft_strncmp(command, "ra\n", 3) && !ra(stack))
		return ;
	if (!ft_strncmp(command, "rb\n", 3) && !rb(stack))
		return ;
	if (!ft_strncmp(command, "rr\n", 3) && !ra(stack) && !rb(stack))
		return ;
	if (!ft_strncmp(command, "rra\n", 3) && !rra(stack))
		return ;
	if (!ft_strncmp(command, "rrb\n", 3) && !rrb(stack))
		return ;
	if (!ft_strncmp(command, "rrr\n", 3) && !rra(stack) && !rrb(stack))
		return ;
}

void	parse_input(char *command, t_two *stack)
{
	if (!check_commands(command))
	{
		free(command);
		free_stacks(stack);
		ft_printf("Error\n");
		exit (255);
	}
	perform_action(command, stack);
}

void	validate_input(char **argv, int argc)
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (check_if_number(argv, argc) || check_min_max(argv, argc)
		|| check_duplicate(argv, argc))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
