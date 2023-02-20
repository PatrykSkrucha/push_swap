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
				return (1);
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
	ft_printf("sorted!\n");
	return (1);
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
	//char *s[20] = {"hah", "hah", "dd"};
	//ft_printf(s[1]);
	//(void)argv;
	//(void)argc;
	//write(2, "a", 1);
	//if (argc < 3)
	//	return (ft_printf("nic") && 1);
	////if (check_if_number(argv, argc) || check_min_max(argv, argc) 
	////	|| check_if_sorted(argv, argc))
	////	return(write(0, "Error", 5));
	//////print_stack(a);
	////if (check_if_number(argv, argc))
	////	return (ft_printf("no") && 1);
	//if (check_duplicate(argv, argc))
	//	return (ft_printf("dupl") && 1);
	//ft_printf("haha");
	arrange_stack(argv, argc);

	return (0);
}