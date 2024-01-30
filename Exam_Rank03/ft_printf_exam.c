/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_exam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdetourn <gdetourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:01:14 by gdetourn          #+#    #+#             */
/*   Updated: 2024/01/25 15:46:39 by gdetourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but 
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

void	ft_putchar(char c, int *ret)
{
	ret += write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_b_un(unsigned int	nbr, char *base, int *ret)
{
	unsigned int	base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbr_b_un((nbr / base_len), base, ret);
		ft_putchar(base[nbr % base_len], ret);
	}
	if (nbr < base_len)
		ft_putchar(base[nbr], ret);
}

void	ft_putnbr_base(long int	nbr, char *base, int *ret)
{
	int	base_len;

	base_len = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ret += write(1, "-", 1);
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base((nbr / base_len), base, ret);
		ft_putchar(base[nbr % base_len], ret);
	}
	if (nbr < base_len)
		ft_putchar(base[nbr], ret);
}

int	ft_putstr(char *s, int *ret)
{
	int	i;

	i = 0;
	if (!s)
	{
		ret += write(1, "(null)", 6);
		return (1);
	}
	while (s[i])
	{
		ret += write(1, &s[i], 1);
		i++;
	}
	return (0);
}

int	ft_check_type(va_list args, const char *format, int *ret)
{
	if (*format == 's')
		ft_putstr((va_arg(args, char *)), ret);
	else if (*format == 'd')
		ft_putnbr_base((va_arg(args, int)), "0123456789", ret);
	else if (*format == 'x')
		ft_putnbr_b_un((va_arg(args, unsigned int)), "0123456789abcdef", ret);
	return (0);
}

int	ft_printf(const char *format, ... )
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_type(args, format, &ret);
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (ret);
}

int	main(void)
{
	ft_printf("ft_: %s\n", "toto");
	printf("%s\n", "toto");
	ft_printf("ft_: Magic %s is %d", "number\n", 42);
	printf("Magic %s is %d", "number\n", 42);
	ft_printf("ft_: Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}
