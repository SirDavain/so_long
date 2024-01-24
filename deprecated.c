/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deprecated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:57:17 by dulrich           #+#    #+#             */
/*   Updated: 2024/01/24 14:57:43 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_line_len(char *str)
{
	size_t	len;

	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	get_line_nbr(int fd)
{
	char	*line;
	int		i;
	int		linecount;

	linecount = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}
