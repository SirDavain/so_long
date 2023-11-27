/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:58:18 by dulrich           #+#    #+#             */
/*   Updated: 2023/11/27 15:36:03 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return ((char *) NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_line_len(int fd)
{
	int		len;
	int		bytes;
	char	buffer[1];

	len = 0;
	bytes = 1;
	buffer[0] = '\0';
	while (1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

int	get_line_nbr(int fd, )
