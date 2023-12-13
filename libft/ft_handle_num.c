/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:11:13 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:52:50 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_count_unum(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*nbr;

	len = ft_count_unum(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (nbr);
}

int	ft_putnbr(int n)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = ft_itoa(n);
	len = ft_putstr(nbr);
	free(nbr);
	return (len);
}

int	ft_unsigned_putnbr(int n)
{
	int		len;
	char	*nbr;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nbr = ft_unsigned_itoa(n);
		len = ft_putstr(nbr);
		free(nbr);
	}
	return (len);
}
