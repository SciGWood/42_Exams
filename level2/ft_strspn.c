/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

DESCRIPTION
       The  strspn()  function calculates the length (in bytes) of the initial
       segment of s which consists entirely of bytes in accept.

RETURN VALUE
       The  strspn()  function returns the number of bytes in the initial seg‐
       ment of s which consist only of bytes from accept.

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stdlib.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break ;
			j++;
		}
		if (accept[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *s = "Hello World!";
    const char *accept = "eloH wrd";

    size_t ft_result = ft_strspn(s, accept);
    size_t std_result = strspn(s, accept);

    printf("ft_strspn result: %zu\n", ft_result);
    printf("strspn result: %zu\n", std_result);

    if (ft_result == std_result)
        printf("Both functions returned the same result.\n");
    else
        printf("The results differ.\n");

    return (0);
}