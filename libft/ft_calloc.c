/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:18:51 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:52:53 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_size;

	total_size = nmemb * size;
	p = malloc(total_size);
	if (p != NULL)
		ft_bzero(p, total_size);
	return (p);
}

// #include <stdio.h>

// int main(void)
// {
// 	size_t	numofelem = 4;
// 	size_t	size = sizeof(int);
// 	int		*arr = (int *)ft_calloc(numofelem, size);
// 	size_t	i;

// 	if (arr != NULL)
// 	{
// 		i = 0;
// 		while (i < numofelem)
// 		{
// 			printf("Element %zu: %d\n", i, arr[i]);
// 			i++;
// 		}
// 		free(arr);
// 	}
// 	else
// 		printf("Memory allocation failed. \n");
// 	return (0);
// }