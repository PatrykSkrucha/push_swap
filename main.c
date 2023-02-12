#include "push_swap.h"

int check_duplicate(char **input, int amount)
{
	int i;
	int tab[128];

	*tab = 0;
	i = 0;
	while (++i < amount)
	{
		if (tab[input[i][0]]++ && tab[input[i][0]] > 1)
			return (1);
	}
	return (0);
}

int validate_input(char **input, int amount)
{
	int i;

	i = 0;
	while (++i < amount)
	{
		if (!ft_isdigit(input[i][0]))
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (check_duplicate(argv, argc) || validate_input(argv, argc))
		return(write(0, "Invalid input", 13));
	//if (check_duplicate(**argv, argc - 1) || validate_input(**argv, argc - 1)
	//	|| check_if_sorted(**argv, argc - 1))
	//	return(write(0, "Invalid input", 13));
	//push_swap(*argv[1], argc - 1);
	ft_printf("here");
	return (1);
}