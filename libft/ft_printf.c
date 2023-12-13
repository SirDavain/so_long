/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dulrich <dulrich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:57:57 by dulrich           #+#    #+#             */
/*   Updated: 2023/10/04 12:53:23 by dulrich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_check_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_printptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_putpercent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_check_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char	*arr;

// 	arr = "Hello world";
// 	ft_printf("%p", arr);
// 	printf("%p", arr);
// 	return (0);
// }