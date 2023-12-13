/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:30:01 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/18 14:12:46 by dulrich          ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		src_len;
	size_t		dst_len;
	const char	*s;

	s = src;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size < 1)
		return (size + src_len);
	i = 0;
	j = ft_strlen(dst);
	while (s[i] && j < size - 1)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (size < dst_len)
		return (src_len + size);
	return (dst_len + src_len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char dst[11] = "a";
// 	int result = ft_strlcat(dst, "lorem", 15);
// 	printf("%i", result);
// }