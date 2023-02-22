#include "push_swap.h"

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int *bubbleSort(char **input, int size)
{
	int	i;
	int	j;
	int *arr;

	i = -1;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	while (++i < size)
		arr[i] = ft_atoi(input[i + 1]);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
	return (arr);
}
