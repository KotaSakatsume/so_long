/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:36:59 by kosakats          #+#    #+#             */
/*   Updated: 2025/02/21 20:35:06 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft2/libft.h"
#include <stdio.h>

static int	handle_format(const char fmt, va_list args)
{
	if (fmt == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (fmt == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (fmt == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	else if (fmt == 'd' || fmt == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (fmt == 'u')
		return (ft_putnbr_u_fd(va_arg(args, unsigned int), 1));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), 1, fmt));
	else if (fmt == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += handle_format(str[++i], args);
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("ft_print\n");
// 	ft_printf(" NULL %s NULL\n ", NULL);
// 	// ft_printf(" %p %p\n ", 0, 0);
// 	// ft_printf(" %p %p\n ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	// ft_printf(" %p %p\n ", ULONG_MAX, -ULONG_MAX);
// 	printf("print\n");
// 	printf(" NULL %s NULL\n ", (char *)NULL);
// 	// printf(" %p %p\n ", (void *)0, (void *)0);
// 	// printf(" %p %p\n ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	// printf(" %p %p\n ", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
// 	return (0);
// }

// int	main(void)
// {
// 	// 	char	*str;
// 	// 	int		num;
// 	// 	str = "ft_printf test!";
// 	// 	num = 123456;
// 	// 	// Basic Tests
// 	ft_printf(" NULL %s NULL\n ", (char *)NULL);
// 	ft_printf(" %p %p\n ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	ft_printf(" %p %p\n ", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p\n ", 0, 0);
// 	printf("----------------------------------------------------\n");
// 	printf(" NULL %s NULL\n ", (char *)NULL);
// 	printf(" %p %p\n ", (void *)LONG_MIN, (void *)LONG_MAX);
// 	printf(" %p %p\n ", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
// 	printf(" %p %p\n ", (void *)0, (void *)0);
// 	// 	ft_printf("Test 5: Unsigned: %u\n", 42);
// 	// 	ft_printf("Test 6: Hexadecimal lowercase: %x\n", 255);
// 	// 	ft_printf("Test 7: Hexadecimal uppercase: %X\n", 255);
// 	// 	ft_printf("Test 8: Percent sign: %%\n");
// 	// 	// Edge Cases
// 	// 	ft_printf("\n-- Edge Cases --\n");
// 	// 	ft_printf("Test 9: Null string: %s\n", (char *)NULL);
// 	// 	ft_printf("Test 10: Zero pointer: %p\n", (void *)0);
// 	// 	ft_printf("Test 11: Maximum integer: %d\n", 2147483647);
// 	// 	ft_printf("Test 12: Minimum integer: %d\n", -2147483648);
// 	// 	ft_printf("Test 13: Zero unsigned: %u\n", 0);
// 	// 	ft_printf("Test 14: Hexadecimal zero: %x\n", 0);
// 	// 	// Field Width and Precision
// 	// 	ft_printf("\n-- Field Width and Precision --\n");
// 	// 	ft_printf("Test 15: Width: %10d\n", num);
// 	// 	ft_printf("Test 16: Precision: %.5d\n", num);
// 	// 	ft_printf("Test 17: Width and Precision: %10.5d\n", num);
// 	// 	ft_printf("Test 18: Left-justified: %-10d\n", num);
// 	// 	ft_printf("Test 19: Zero-padding: %010d\n", num);
// 	// 	// Combining Specifiers
// 	// 	ft_printf("\n-- Combining Specifiers --\n");
// 	// 	ft_printf("Test 20: Width and String: %10s\n", "hello");
// 	// 	ft_printf("Test 21: Precision and String: %.5s\n", "hello");
// 	// 	ft_printf("Test 22: Width and Pointer: %20p\n", &str);
// 	// 	ft_printf("Test 23: Left-justified and Hex: %-10x\n", 255);
// 	// 	// Special Characters
// 	// 	ft_printf("\n-- Special Characters --\n");
// 	// 	ft_printf("Test 24: Newline: \\n\n");
// 	// 	ft_printf("Test 25: Tab: \\t\n");
// 	// 	ft_printf("Test 26: Backslash: \\\\\n");
// 	// 	// Stress Tests
// 	// 	ft_printf("\n-- Stress Tests --\n");
// 	// 	ft_printf("Test 27: Large Width: %50s\n", "ft_printf is awesome!");
// 	// 	ft_printf("Test 28: Large Integer: %d\n", 1000000000);
// 	// 	ft_printf("Test 29: Repeated Percent: %%%% Percent %%\n");
// 	// 	// Mixed Outputs
// 	// 	ft_printf("\n-- Mixed Outputs --\n");
// 	// 	ft_printf("Test 30: Mixed: Char: %c, String: %s, Int: %d, Hex: %x\n",
// 	// 'Z',
// 	// 		"Mixing", 123, 0xabc);
// 	// 	return (0);
// }
