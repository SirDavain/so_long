/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:38:33 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/08 10:09:47 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_totallen(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*s3;
	size_t	i;
	size_t	j;

	total_len = ft_totallen(s1, s2) + 1;
	s3 = (char *)malloc((total_len) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

/*#include <stdio.h>

int main(void)
{
	const char	*s1 = "Hello ";
	const char	*s2 = "World.";
	char		*result = ft_strjoin(s1, s2);

	printf("%s", result);
}*/