/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:32:59 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/20 13:45:36 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (free(s1), NULL);
		s1[0] = '\0';
	}
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_new_strchr(const char *s, int c)
{
	char	*str;
	char	nl;

	if (!s)
		return (NULL);
	str = (char *)s;
	nl = (char)c;
	while (*str)
	{
		if (*str == nl)
			return ((char *)str);
		str++;
	}
	if (*str == nl)
		return ((char *)str);
	return (NULL);
}
