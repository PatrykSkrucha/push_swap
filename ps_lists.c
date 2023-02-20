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

void print_list(small_stack *lst)
{
	small_stack *temp;
	
	temp = lst;
	while(temp != NULL)
	{
		ft_printf("%i\n", temp->number);
		temp = temp->next;
	}
}

void	add_back(big_stack *lst, small_stack *new, int control)
{
	small_stack	*temp;

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

void	add_front(big_stack *lst, small_stack *new, int control)
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

int	lstsize(small_stack  *lst)
{
	int	i;

	i = 0;
	//ft_printf("gg");
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void move_forward_a(big_stack *stack)
{
	big_stack *temp;
	small_stack *head;

	temp = stack;
	head = new_list(lstlast(temp->stack_a)->number);
	add_front(temp, head, 1);

	while (temp->stack_a != NULL)
	{
		if (temp->stack_a->next->next == NULL)
		{

			temp->stack_a->next = NULL;
		}
		//{
		//	ft_printf("ten: %i\nnastepny: %i", temp->number, temp->next->number);
		//}
		temp->stack_a = temp->stack_a->next;
	}
	temp->stack_a = head;
	print_list(temp->stack_a);
	//ft_printf("%i", tail->number);
}