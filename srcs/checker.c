#include "push_swap_bonus.h"

int main(int argc, char **argv)
{
	char *str;
	size_t	amount;

	amount = 1;
	str = malloc(5);
	while (amount > 0)
	{
		amount = read(0, str, 4);
		str[amount] = '\0';
		ft_printf("%s", str);
	}

	ft_printf("jeszcze tu");
	return (0);
}