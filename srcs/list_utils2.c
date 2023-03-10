/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:46 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/10 19:03:42 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	del_first(t_two *stack, int control)
{
	t_single	*head;

	if (control)
	{
		head = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = head;
	}
	else
	{
		head = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = head;
	}
}

void	set_index(t_single *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

t_single	*get_node(t_single *stack, int index)
{
	t_single	*temp;

	temp = stack;
	while (temp->index != index)
		temp = temp->next;
	return (temp);
}

t_map	*new_map(void)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = allocate_map();
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->best_solution = ft_calloc(6, 4);
	new->best_path = ft_calloc(6, 4);
	if (!new->best_path || !new->best_solution)
	{
		free_map(new);
		return (NULL);
	}
	return (new);
}

t_two	*arrange_stack(char **input, int amount, t_two *stack)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	while (++i < amount)
	{
		j = -1;
		str = ft_split(input[i], ' ');
		if ((!str || !better_strlen(input[i])) && !free_stacks(stack))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
		if (check_and_appent(str, stack, &j))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free_input(str);
			free_stacks(stack);
			exit (EXIT_FAILURE);
		}
		free_input(str);
	}
	set_index(stack->stack_a);
	return (stack);
}
