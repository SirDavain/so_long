/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:33:17 by dulrich           #+#    #+#             */
/*   Updated: 2024/02/20 14:28:23 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*save_remainder(char *read_line)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free(read_line);
		return (NULL);
	}
	remainder = malloc(sizeof(char) * (ft_strlen(read_line) - i) + 1);
	if (!remainder)
	{
		free(read_line);
		return (NULL);
	}
	i++;
	j = 0;
	while (read_line[i])
		remainder[j++] = read_line[i++];
	remainder[j] = '\0';
	free(read_line);
	return (remainder);
}

char	*read2str(char *read_line)
{
	int		i;
	char	*str;

	if (!read_line[0])
		return (NULL);
	i = 0;
	while (read_line[i] != '\n' && read_line[i] != '\0')
		i++;
	if (read_line[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
		str[i] = read_line[i];
	return (str);
}

char	*read_newline(int fd, char *read_line)
{
	char	*buf;
	int		read_bytes;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_new_strchr(read_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			free(read_line);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		read_line = ft_new_strjoin(read_line, buf);
	}
	free(buf);
	return (read_line);
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		*the_next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = read_newline(fd, read_line);
	if (!read_line)
		return (NULL);
	the_next_line = read2str(read_line);
	read_line = save_remainder(read_line);
	return (the_next_line);
}

/* #include <stdio.h>

int	main(void)
{
	int lines = 1;
	char *print_line;
	//int fd = 0; 
	int fd = open("../testing/lorem.txt", O_RDONLY);
	while ((print_line = get_next_line(fd)))
	{
		printf("%d->%s", lines++, print_line);
		free(print_line);
	}
	return (0);
} */
