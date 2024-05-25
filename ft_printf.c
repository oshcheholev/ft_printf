/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:01:44 by oshcheho          #+#    #+#             */
/*   Updated: 2024/05/24 11:13:12 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
// #include "./libft/libft.h"
#include "ft_printf.h"

static int	ft_choose(char c, va_list args)
{
	unsigned long	ptr;

	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd_unsigned(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), c));
	else if (c == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			return (ft_putstr_fd("(nil)", 1));
		return (ft_putnbr_base_fd(ptr, c));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result += ft_choose(str[i + 1], args);
			i++;
		}
		else
			result += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}

// int main (void) 
// {
// 	int i = printf(NULL, 10);
// 	int n = ft_printf(NULL, 10);

// 	printf("n = %d\n", n);
// 	printf("i = %d\n", i);
// }
// 	i = ft_printf("%d C is lowest temp", -273);
// 	printf("i = %d", i);
// }
// int main() {
// 	char *str = NULL;
//     // Test strings
//     ft_printf("lo, World!\n");
//     ft_printf("This is a %s\n", str);
//     ft_printf("Empty string: %s\n", str);
//     printf("Empty string: %s\n", str);
//     ft_printf("Long string: %s\n", "A very very long");

//     // Test integers
//     ft_printf("Integer: %d\n", 42);
//     printf("Int: %d\n", 42);
//     ft_printf("Negative integer: %d\n", -42);
//     printf("Neg integer: %d\n", -42);
//     ft_printf("Large integer: %d\n", 2147483647); // INT_MAX
//     printf("Lar integer: %d\n", 2147483647); // INT_MAX
//     ft_printf("Small integer: %d\n", -2147483648); // INT_MIN
// //    printf("Sma integer: %d\n", -2147483648); // INT_MIN
//     ft_printf("Small integer: %d\n", -2147483648); // INT_MIN
// //    printf("Sma integer: %d\n", -2147483648); // INT_MIN

//     // Test characters
//     ft_printf("Percent sign: %%\n");
//     ft_printf("Character: %c\n", 'A');
// printf("Character: %c\n", 'A');

//     // Test hexadecimal
//     ft_printf("Hex low: %x\n", 55); // FF 
// printf("Hex lowe: %x\n", 55); // FF in hex
//     ft_printf("Hex upp: %X\n", 155); // FF in hexadecimal
// printf("Hex lowe: %x\n", 155); // FF in hexadecimal

//     // Test pointer
//     int r = 22;
// 	int *p = &r;
//     ft_printf("Pointer: %p\n", p);
//     printf("Pointer: %p\n", p);

//     // Edge case: invalid format specifier
//     ft_printf("Invalid format: %z\n");

//     // Mixed cases
//     ft_printf("M: %s, %d, %c, %x, %X, %u, %p\n",
		// "e", 1, 'Z', 25, 50, 23, &p);

//     return 0;
// }