#include "push_swap.h"

t_single	*new_list(int content)
{
	t_single	*new;

	new = (t_single *)malloc(sizeof(t_single));
	if (!new)
		return (NULL);
	new->number = content;
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


void	add_back(t_two *lst, t_single *new, int control)
{
	t_single	*temp;

	if (control)
	{
		if (lst->stack_a == NULL)
		{
			lst->stack_a = new;
			return ;
		}
		temp = lstlast(lst->stack_a);
		temp->next = new;
	}
	else
	{
		if (lst->stack_b == NULL)
		{
			lst->stack_b = new;
			return ;
		}
		temp = lstlast(lst->stack_b);
		temp->next = new;
	}
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
