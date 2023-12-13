/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:06:25 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:30:53 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_putptr(p / 16);
		ft_putptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p - 10 + 'a');
	}
}

int	ft_ptr_len(uintptr_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

int	ft_printptr(uintptr_t p)
{
	int	len;

	len = 0;
	if (p == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		ft_putptr(p);
		len += ft_ptr_len(p);
	}
	return (len);
}
