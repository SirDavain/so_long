/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:53:47 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:20 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (un_s1[i] > un_s2[i])
			return (1);
		if (un_s1[i] < un_s2[i])
			return (-1);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *s1 = "atoms\0\0\0\0";
// 	char *s2 = "atoms\0abc";
// 	int	result;
// 	result = ft_memcmp(s1, s2, 8);
// 	printf("%i", result);
// }