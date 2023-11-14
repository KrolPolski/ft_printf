/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/14 13:37:46 by rboudwin         ###   ########.fr       */
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

void	ft_putnbr_unsigned(unsigned int n, int fd, int *len)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, fd, len);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		(*len)++;
	}
}

static void	ft_puthex_converter(unsigned long n, int caps, int *len)
{
	if (n >= 16)
	{
		ft_puthex_converter(n / 16, caps, len);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (caps == 0)
				ft_putchar_fd(n + 87, 1);
			else if (caps == 1)
				ft_putchar_fd(n + 55, 1);
		}
		(*len)++;
	}
}

static void	ft_puthex(long n, int caps, int *len)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*len)++;
		n = -n;
	}
	ft_puthex_converter((unsigned long)n, caps, len);
}

static void	ft_putpointer(unsigned long n, int caps, int *len)
{
	ft_puthex_converter(n, caps, len);
}

int	ft_log10(int n)
{
	int result;

	result = 0;
	while (n / 10 != 0)
	{
		result++; 
		n = n / 10;
	}
	return result;
}
void	ft_fetch_integer(va_list args, int *len)
{
	int n;

	n = va_arg(args, int);
	if (n < 0)
	{
		(*len)++;
		n = -n;
		ft_putchar_fd('-', 1);
	}
	ft_putnbr_fd(n, 1);
	(*len) = (*len) + 1 + ft_log10(n);
}

int	ft_identify_data_type(char const *c, int i, va_list args, int *len)
{
	void			*ptr;
	unsigned long	ptr_long;
	int				n;
	char			*str;

	i++;
	if (c[i] == '%')
	{
		ft_putchar_fd('%', 1);
		(*len)++;
	}
	else if (c[i] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*len)++;
	}
	else if (c[i] == 'd' || c[i] == 'i')
		ft_fetch_integer(args, len);
	else if (c[i] == 'p')
	{
		ptr = va_arg(args, void *);
		ptr_long = (unsigned long)ptr;
		ft_putstr_fd("0x", 1);
		*len = (*len) + 2;
		ft_putpointer(ptr_long, 0, len);
	}
	else if (c[i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			ft_putstr_fd("(null)", 1);
			*len = (*len) + 6;
		}
		else
		{
			ft_putstr_fd(str, 1);
			*len = (*len) + ft_strlen(str);
		}
	}
	else if (c[i] == 'u')
	{
		n = va_arg(args, unsigned int);
		printf("n is currently %d\n", n);
		ft_putnbr_unsigned(n, 1, len);
	}
	else if (c[i] == 'x')
		ft_puthex(va_arg(args, int), 0, len);
	else if (c[i] == 'X')
		ft_puthex(va_arg(args, int), 1, len);
	return (i);
}

int	ft_printf(const char *c, ...)
{
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
			(ft_putchar_fd(c[i], 1));
//			printf("current len is %d\n", len);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
