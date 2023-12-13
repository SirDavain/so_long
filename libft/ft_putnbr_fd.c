/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:19:06 by dulrich           #+#    #+#             */
/*   Updated: 2023/09/15 16:32:07 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;
	int		i;
	char	buffer[12];

	n_long = n;
	if (n_long == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n_long < 0)
	{
		n_long *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (n_long)
	{
		buffer[i++] = (n_long % 10) + 48;
		n_long /= 10;
	}
	while (i > 0)
		write(fd, &buffer[--i], 1);
}
