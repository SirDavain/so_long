/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:44:35 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:21 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*un_dest;
	unsigned char	*un_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	un_dest = (unsigned char *)dest;
	un_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		un_dest[i] = un_src[i];
		i++;
	}
	return ((void *)un_dest);
}

/*#include <stdio.h>
int main(void)
{
	unsigned char dest[50];
	unsigned char src[] = "Hello World";
	size_t n = 5;

	ft_memcpy(dest, src, n);
	printf("%s", dest);
}*/