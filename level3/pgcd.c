/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
---------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$*/

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	nb1;
	int	nb2;
	int	swap;

	nb1 = 0;
	nb2 = 0;
	swap = 0;
	if(argc == 3)
	{
		nb1 = atoi(argv[1]);
		nb2 = atoi(argv[2]);
		while (nb2 != 0)
		{
			swap = nb2;
			nb2 = nb1 % nb2;
			nb1 = swap;
		}
		printf("%d", nb1);
	}
	printf("\n");
	return (0);
}