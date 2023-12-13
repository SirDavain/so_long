/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:06:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:24 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	unsigned_c;

	x = (unsigned char *)s;
	unsigned_c = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		x[i] = unsigned_c;
		i++;
	}
	return (x);
}

/*#include <stdio.h>
int	main(void)
{
	char	s[] = "Hi there";
	size_t	n;
	int		c;

	n = 3;
	c = '.';
	ft_memset(s, c, n);
	printf("%s", s);
}*/
