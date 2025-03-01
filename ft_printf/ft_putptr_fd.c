/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:30:29 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/22 22:58:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft2/libft.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long	n;
	int				count;

	count = 0;
	n = (unsigned long)ptr;
	if (n == 0)
	{
		count += ft_putstr_fd("(nil)", fd);
	}
	else
	{
		count += ft_putstr_fd("0x", fd);
		count += ft_puthex_fd(n, fd, 'x');
	}
	return (count);
}
