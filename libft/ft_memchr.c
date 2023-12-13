/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:26:07 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:13 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	un_c;
	unsigned char	*x;
	size_t			i;

	x = (unsigned char *)s;
	un_c = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (un_c == x[i])
			return ((void *)(x + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
	unsigned char	src[] = "Hello World";
	int				c = 'o';
	size_t n = 5;

	void *result = ft_memchr(src, c, n);
	if (result != NULL)
		printf("%c", *(unsigned char *)result);
	else
		printf("Char not found.");
	return (0);
}*/