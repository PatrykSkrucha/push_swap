#include "push_swap.h"

int check_duplicate(char **input, int amount)
{
	int	i;
	int	j;

	i = 0;
	while (++i < amount - 1)
	{
		j = i;
		while (++j < amount)
		{
			if (ft_strncmp(input[i], input[j], ft_strlen(input[i])) == 0)
				return (ft_printf("duplicate %s and %s", input[i], input[j]) && 1);
		}
	}
	return (0);
}

int check_if_number(char **input, int amount)
{
	int i;
	int	j;
	int	len;

	i = 0;
	while (++i < amount)
	{
		j = -1;
		len = ft_strlen(input[i]);
		while (++j < len)
		{
			if (input[i][j] == '-')
				j++;
			if (input[i][j] < 48 || input[i][j] > 57)
				return (ft_printf("not a number\n") && 1);
		}
	}
	return (0);
}

int check_if_sorted(char **input, int amount)
{
	int	i;

	i = 0;
	while (++i < amount - 1)
	{
		if (ft_atoi((const char*)input[i]) > ft_atoi((const char*)input[i + 1]))
			return (0);
	}
	return (ft_printf("sorted") && 1);
}

int check_min_max(char **input, int amount)
{
	int	i;

	i = 0;
	while (++i < amount)
	{
		if (ft_atoi((const char*)input[i]) != ft_atoi_long(input[i]))
			return (ft_printf("min_max\n") && 1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	// spr ktore musza byc static
	//if (argc < 3 || check_if_sorted(argv, argc))
	//	return (0);
	//if (check_if_number(argv, argc) || check_min_max(argv, argc) || check_duplicate(argv, argc))
	//	return(write(1, "Error\n", 6));
	big_stack *stack;
	stack = arrange_stack(argv, argc);
	radix(stack, argc);
	//bubbleSort(argv, argc - 1);
	//free_everything(stack);
	//if(stack->stack_a->number < 0 && ((stack->stack_a->number * -1) >> 0 & 1))
	//	ft_printf("haha");
	//ft_printf("%i", sort_check_asc(stack->stack_a, stack));
	return (0);
}