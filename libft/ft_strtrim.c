/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:15:12 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/18 15:50:09 by dulrich          ###   ########.fr       */
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

// char	*ft_strchr(const char *s, int c)
// {
// 	int				i;
// 	unsigned char	uc;

// 	uc = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (uc == s[i])
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (uc == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	src_len = ft_strlen(src);
// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (src[i] && i < size - 1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (src_len);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		end;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = s1_len - 1;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	s2_len = end - start + 1;
	s2 = (char *)malloc((s2_len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, s2_len + 1);
	s2[s2_len] = '\0';
	return (s2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1 = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char	*set = " ";
// 	char	*result = ft_strtrim(s1, set);

// 	printf("%s", result);
// }