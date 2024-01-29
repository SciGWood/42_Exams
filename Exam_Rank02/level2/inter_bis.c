/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/

#include <unistd.h>

int	ft_strnchr_bool(char c, char *str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	ft_strchr_bool(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_strchr_bool(argv[1][i], argv[2]) == 1
				&& ft_strnchr_bool(argv[1][i], argv[1], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
