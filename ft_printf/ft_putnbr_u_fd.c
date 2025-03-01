/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:30:13 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/22 22:58:02 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft2/libft.h"

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}
