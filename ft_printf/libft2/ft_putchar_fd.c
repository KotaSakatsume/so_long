/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:28:43 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/22 22:27:21 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (1);
}

// int	main(void)
// {
// 	ft_putchar_fd('a', 1);
// 	return (0);
// }
