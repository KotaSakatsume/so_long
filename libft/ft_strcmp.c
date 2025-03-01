/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:55:43 by kosakats          #+#    #+#             */
/*   Updated: 2024/09/09 21:33:36 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "ABC";
// 	char	str2[] = "AAAAAA";

// 	printf("%d", ft_strcmp(str1, str2));
// 	return (0);
// }
