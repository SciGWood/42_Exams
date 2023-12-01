/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

DESCRIPTION
       The strcspn() function calculates the length of the initial segment of
       s which consists entirely of bytes not in reject.

RETURN VALUE
       The strcspn() function returns the number of bytes in the initial seg‐
       ment of s which are not in the string reject.

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (j);
			j++;
		}
		i++;
	}
	return (i);
}
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
    char str1[] = "Hello world";
    char str2[] = "Hello";
    char str3[] = "world";
    char str4[] = "12345";
    char str5[] = "67890";
    char str6[] = "1234567890";
    char reject1[] = " ";
    char reject2[] = "rlo";
    char reject3[] = "789";

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject1));
    printf("strcspn: %zu\n", strcspn(str1, reject1));

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject2));
    printf("strcspn: %zu\n", strcspn(str1, reject2));

    printf("ft_strcspn: %zu\n", ft_strcspn(str1, reject3));
    printf("strcspn: %zu\n", strcspn(str1, reject3));

    printf("ft_strcspn: %zu\n", ft_strcspn(str2, str3));
    printf("strcspn: %zu\n", strcspn(str2, str3));

    printf("ft_strcspn: %zu\n", ft_strcspn(str4, str5));
    printf("strcspn: %zu\n", strcspn(str4, str5));

    printf("ft_strcspn: %zu\n", ft_strcspn(str6, reject3));
    printf("strcspn: %zu\n", strcspn(str6, reject3));

    return (0);
}