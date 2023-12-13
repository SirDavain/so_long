/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:22:44 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/18 11:47:16 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*un_s1;
// 	unsigned char	*un_s2;

// 	un_s1 = (unsigned char *)s1;
// 	un_s2 = (unsigned char *)s2;
// 	i = 0;
// 	while (un_s1[i] == un_s2[i] && i < n && un_s1[i] && un_s2[i])
// 		i++;
// 	if (un_s1[i] > un_s2[i])
// 		return (1);
// 	else if (un_s1[i] < un_s2[i])
// 		return (-1);
// 	else
// 		return (0);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (un_s1[i] != un_s2[i] || un_s1[i] == '\0' || un_s2[i] == '\0')
			return (un_s1[i] - un_s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *s1 = "abcdef";
// 	char *s2 = "abcdefghijklmnop";
// 	int	result;
// 	result = ft_strncmp(s1, s2, 6);
// 	printf("%i", result);
// }