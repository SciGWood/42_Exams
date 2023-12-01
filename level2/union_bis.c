/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union 
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if (ft_strnchr_bool(argv[1][i], argv[1], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i--;
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (ft_strnchr_bool(argv[2][j], argv[1], i) == 0
				&& ft_strnchr_bool(argv[2][j], argv[2], j) == 0)
				write(1, &argv[2][j], 1);
			j++;
		}

	}
	write(1, "\n", 1);
	return (0);
}