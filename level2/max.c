/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

#include <stdlib.h>

int	max(int* tab, unsigned int len)
{
	unsigned int	i;
	int max;

	i = 1;
	max = tab[0];
	if (tab == NULL || len == 0)
		return (0);
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}