/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
-----------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdlib.h>

int	ft_nb_digit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				count;
	unsigned int	i;

	count = 0;
	count = ft_nb_digit(n);
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	i = 0;
	i = n;
	if (n < 0)
		i = -n;
	while (0 < count)
	{
		count--;
		str[count] = (i % 10) + '0';
		i /= 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
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
