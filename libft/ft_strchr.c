/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:03:47 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/03 15:16:29 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (uc == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char		*src = "Hello";
// 	char		*test = ft_strchr(src, '\0');

// 	if (test != NULL)
// 		printf("%c", *test);
// 	else
// 		printf("Char not found.\n");
// }
