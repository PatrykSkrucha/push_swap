#include "push_swap.h"

small_stack	*new_list(int content)
{
	small_stack	*new;

	new = (small_stack *)malloc(sizeof(small_stack));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}

small_stack	*lstlast(small_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	add_back(small_stack **lst, small_stack *new)
{
	small_stack	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = lstlast(*lst);
	temp->next = new;
}

void	ft_lstadd_front(small_stack **lst, small_stack *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
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