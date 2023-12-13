/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:11:28 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/18 13:26:19 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (uc == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*s;
// 	int			c;
// 	char		*result;

// 	s = "Hell\0o";
// 	c = '\0';
// 	result = ft_strrchr(s, c);

// 	if (result != NULL)
// 		printf("%c", *result);
// 	else
// 		printf("Char not found.\n");
// }