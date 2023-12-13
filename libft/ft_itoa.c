/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:23:24 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:10 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_num(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_handle_negative_nbr(char *s, int n, int *offset)
{
	if (n < 0)
	{
		s[0] = '-';
		*offset = 1;
		return (-n);
	}
	return (n);
}

static void	ft_to_str(char *s, int n, int len)
{
	while (len > 0)
	{
		len--;
		s[len] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	int		offset;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_count_num(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	offset = 0;
	n = ft_handle_negative_nbr(s, n, &offset);
	ft_to_str(s + offset, n, len - offset);
	return (s);
}
