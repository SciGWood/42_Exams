/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>

int	ft_issep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char	**ft_split(char *str)
{
	int		i = 0;
	int		word = 0;
	int		cha;
	char	**tab;

	tab = malloc(sizeof(char *) * 4096);
	if (!tab)
		return (NULL);
	while (ft_issep(str[i]))
		i++;
	while (str[i] != '\0')
	{
		cha = 0;
		tab[word] = malloc(sizeof(char) * 4096);
		if (!tab[word])
			return (NULL);
		while (!ft_issep(str[i]) && str[i] != '\0')
		{
			tab[word][cha] = str[i];
			cha++;
			i++;
		}
		tab[word][cha] = '\0';
		while (ft_issep(str[i]))
			i++;
		word++;
	}
	tab[word] = NULL;
	return(tab);
}

#include <stdio.h>
int main(int ac, char **av)
{
	int	i = 0;
	char	**tab = NULL;

	if (ac == 2)
	{
		tab = ft_split(av[1]);
		while (tab[i] != NULL)
		{
			printf("%s\n", tab[i]);
			free(tab[i]);
			i++;
		}
    }
    free(tab);
    return 0;
}