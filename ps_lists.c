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
	while(lst != NULL)
	{
		ft_printf("%i\n", lst->number);
		lst = lst->next;
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
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void move_forward_a(big_stack *stack)
{
	small_stack *head;

	head = new_list(lstlast(stack->stack_a)->number);
	add_front(stack, head, 1);

	while (stack->stack_a != NULL)
	{
		if (stack->stack_a->next->next == NULL)
		{
			free(stack->stack_a->next);
			stack->stack_a->next = NULL;
		}
		stack->stack_a = stack->stack_a->next;
	}
	stack->stack_a = head;
	ft_printf("rra\n");
}

void move_backwards_a(big_stack *stack)
{
	small_stack *head;

	if (lstsize(stack->stack_a) > 1)
	{
		head = stack->stack_a->next;
		add_back(stack, new_list(stack->stack_a->number), 1);
		free(stack->stack_a);
		stack->stack_a = head;
		ft_printf("ra\n");
	}
}

void del_first(big_stack *stack, int control)
{
	small_stack *head;

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

void push_b(big_stack *stack)
{
	if (stack->stack_a)
	{
		add_front(stack, new_list(stack->stack_a->number), 0);
		del_first(stack, 1);
		ft_printf("pb\n");
	}
}

void push_a(big_stack *stack)
{
	if (stack->stack_b)
	{
		add_front(stack, new_list(stack->stack_b->number), 1);
		del_first(stack, 0);
		ft_printf("pa\n");
	}
}

int sort_check_desc(small_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number <  stack->next->number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void free_everything(big_stack *stack)
{
	small_stack *temp;
	big_stack *temp_stack;
	
	temp = stack->stack_a;
	temp_stack = stack;
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
int sort_check_asc(small_stack *stack, big_stack *container)
{
	small_stack *head = stack;
	while (stack->next != NULL)
	{
		if (stack->number >  stack->next->number)
			return (1);
		stack = stack->next;
	}
	if (!container->stack_b)
	{
		free_everything(container);
		exit (0);
	}
	//else
		//return (0);
}