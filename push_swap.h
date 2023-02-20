#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <limits.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	small_stack;

typedef struct two_stacks
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

}	big_stack;


small_stack	*new_list(int content);
void print_list(small_stack *lst);
small_stack	*lstlast(small_stack *lst);
void	add_back(big_stack *lst, small_stack *new, int control);
void	add_front(big_stack *lst, small_stack *new, int control);
int	lstsize(small_stack  *lst);
void arrange_stack(char **input, int amount);
void move_forward_a(big_stack *stack);

#endif