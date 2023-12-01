/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
-----------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		i;
	int 	tmp;
	char	*str;

	i = 0;
	tmp = nbr;
	if (nbr == -2147483648)
		return("-2147483648");
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
		str[0] = '-';
	}
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	i--;
	while (nbr)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	return (str);
}

#include <stdio.h>
int main()
{
    int number = -12345;
    char *result = ft_itoa(number);

    if (result)
    {
        printf("Le nombre %d sous forme de chaîne est : %s\n", number, result);
        free(result); // N'oubliez pas de libérer la mémoire allouée
    }
    else
    {
        printf("Erreur lors de l'allocation mémoire.\n");
    }

    return 0;
}