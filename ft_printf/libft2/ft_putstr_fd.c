/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:42:00 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/22 21:57:19 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s || s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (s && s[count])
		count += ft_putchar_fd(s[count], fd);
	return (count);
}

// int	main(void)
// {
// 	printf("%d\n", ft_putstr_fd(NULL, 1));
// 	return (0);
// }
