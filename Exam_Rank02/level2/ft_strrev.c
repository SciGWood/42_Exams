/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Écrire une fonction qui inverse (en place) une chaîne de caractères.

Elle devra renvoyer son paramètre.

Votre fonction devra être prototypée de la façon suivante :

char    *ft_strrev(char *str);*/

#include <stdlib.h>

char	*ft_strrev(char *str)
{
	char	tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (!str)
		return (NULL);
	while (str[end])
		end++;
	end--;
	while (str && start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}

#include <stdio.h>

int	main()
{
	char str[] = "Hello World";

	printf("Original string: %s\n", str);
	ft_strrev(str);
	printf("Reversed string: %s\n", str);
	return (0);
}