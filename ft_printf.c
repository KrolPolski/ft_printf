/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/14 15:10:06 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The plan:
 *
 * 1. Implement simple printing of a string
 * 2. Implement inserting characters
 * 3. Implement inserting strings
 * 3. Implement the ability to insert integers
 * 4. Implement inserting pointers
 * 5. Implement other data types
 * 6. Implement optional flags
 *
 * */
/* Requirements:
 * 1. Write a string
 * 2. Allow insertion of alternate data types (likely leveraging
 * 		ft_strjoin and ft_itoa, for example) by using arguments
 * 3. Make sure that you can use the return value of the function as an arg
 *
 * We do not have to implement buffer management
 * */
#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_unsigned(unsigned int n, int fd, int *len, int a)
{
	if (n >= 10)
	{
		a = ft_putnbr_unsigned(n / 10, fd, len, a);
		if (a == -1)
			return (a);
		n = n % 10;
	}
	if (n < 10)
	{
		a = ft_putchar_fd(n + '0', fd);
		if (a == -1)
			return (a);
		(*len)++;
	}
	return (a);
}

static int	ft_puthex_converter(unsigned long n, int caps, int *len, int a)
{
	if (n >= 16)
	{
		a = ft_puthex_converter(n / 16, caps, len, a);
		if (a == -1)
			return (a);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			a = ft_putchar_fd(n + '0', 1);
		else
		{
			if (caps == 0)
				a = ft_putchar_fd(n + 87, 1);
			else
				a = ft_putchar_fd(n + 55, 1);
		}
		(*len)++;
		if (a == -1)
			return (a);
	}
	return (0);
}

static int	ft_puthex(unsigned int n, int caps, int *len)
{
	int	a;

	a = 0;
	return (ft_puthex_converter(n, caps, len, a));
}

static int	ft_putpointer(unsigned long n, int caps, int *len)
{
	int	a;

	a = 0;
	return (ft_puthex_converter(n, caps, len, a));
}

int	ft_log10(int n)
{
	int	result;

	result = 0;
	while (n / 10 != 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

int	ft_fetch_integer(va_list args, int *len)
{
	int	n;
	int	a;

	n = va_arg(args, int);
	if (n == -2147483648)
	{
		a = ft_putstr_fd("-2147483648", 1);
		if (a == -1)
			return (a);
		*len = (*len) + 11;
		return (a);
	}
	if (n < 0)
	{
		(*len)++;
		n = -n;
		a = ft_putchar_fd('-', 1);
		if (a == -1)
			return (a);
	}
	a = ft_putnbr_fd(n, 1);
	if (a == -1)
		return (a);
	(*len) = (*len) + 1 + ft_log10(n);
	return (a);
}

int	ft_identify_data_type(char const *c, int i, va_list args, int *len)
{
	void			*ptr;
	unsigned long	ptr_long;
	int				n;
	char			*str;
	int				a;

	i++;
	if (c[i] == '%')
	{
		a = ft_putchar_fd('%', 1);
		if (a == -1)
			return (a);
		(*len)++;
	}
	else if (c[i] == 'c')
	{
		a = ft_putchar_fd(va_arg(args, int), 1);
		if (a == -1)
			return (a);
		(*len)++;
	}
	else if (c[i] == 'd' || c[i] == 'i')
	{
		a = ft_fetch_integer(args, len);
		if (a == -1)
			return (a);
	}
	else if (c[i] == 'p')
	{
		ptr = va_arg(args, void *);
		ptr_long = (unsigned long)ptr;
		a = ft_putstr_fd("0x", 1);
		if (a == -1)
			return (a);
		*len = (*len) + 2;
		a = ft_putpointer(ptr_long, 0, len);
		if (a == -1)
			return (a);
	}
	else if (c[i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			a = ft_putstr_fd("(null)", 1);
			if (a == -1)
				return (a);
			*len = (*len) + 6;
		}
		else
		{
			a = ft_putstr_fd(str, 1);
			if (a == -1)
				return (a);
			*len = (*len) + ft_strlen(str);
		}
	}
	else if (c[i] == 'u')
	{
		n = va_arg(args, unsigned int);
		a = ft_putnbr_unsigned(n, 1, len, 0);
		if (a == -1)
			return (a);
	}
	else if (c[i] == 'x')
	{
		a = ft_puthex(va_arg(args, int), 0, len);
		if (a == -1)
			return (a);
	}
	else if (c[i] == 'X')
	{
		a = ft_puthex(va_arg(args, int), 1, len);
		if (a == -1)
			return (a);
	}
	return (i);
}

int	ft_printf(const char *c, ...)
{
	int		a;
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
			i = ft_identify_data_type(c, i, args, &len);
		else
		{
			a = ft_putchar_fd(c[i], 1);
			if (a == -1)
				return (a);
			len++;
		}
		if (i == -1)
			return (i);
		i++;
	}
	va_end(args);
	return (len);
}
