/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskrucha <pskrucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:00 by pskrucha          #+#    #+#             */
/*   Updated: 2023/03/03 17:52:51 by pskrucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_single	*new_list(int content)
{
	t_single	*new;

	new = (t_single *)malloc(sizeof(t_single));
	if (!new)
		return (NULL);
	new->number = content;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_single	*lstlast(t_single *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	add_back(t_two *lst, t_single *new, int control)
{
	t_single	*temp;

	if (!new)
		return (1);
	if (control)
	{
		if (lst->stack_a == NULL)
		{
			lst->stack_a = new;
			return (0);
		}
		temp = lstlast(lst->stack_a);
		temp->next = new;
	}
	else
	{
		if (lst->stack_b == NULL)
		{
			lst->stack_b = new;
			return (0);
		}
		temp = lstlast(lst->stack_b);
		temp->next = new;
	}
	return (0);
}

void	add_front(t_two *lst, t_single *new, int control)
{
	if (control)
	{
		new->next = lst->stack_a;
		lst->stack_a = new;
	}
	else
	{
		new->next = lst->stack_b;
		lst->stack_b = new;
	}
}

int	lstsize(t_single *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
