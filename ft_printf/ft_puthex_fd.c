/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:29:32 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/22 22:58:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft2/libft.h"

int	ft_puthex_fd(unsigned long n, int fd, char x)
{
	int		count;
	char	*hex;

	count = 0;
	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_fd(n / 16, fd, x);
	count += ft_putchar_fd(hex[n % 16], fd);
	return (count);
}
