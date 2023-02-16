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


void printi();

#endif