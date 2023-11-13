/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 17:08:05 by rboudwin         ###   ########.fr       */
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

void	ft_putnbr_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
}

static void	ft_puthex_converter(long n, int caps)
{
if (n >= 16)
	{
		ft_puthex_converter(n / 16, caps);
		n = n % 16;
	}
	if (n < 16)
	{	
		if (n < 10)
			ft_putchar_fd(n + '0', 1);
		else
			if (caps == 0)
				ft_putchar_fd(n + 87, 1);
			else if (caps == 1)
				ft_putchar_fd(n + 55, 1);
	}
}
static void ft_puthex(long n, int caps)
{
	if (n == -2147483648)
	{
		write(1, "-0x80000000", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	// ft_putstr_fd("0x", 1);

	ft_puthex_converter(n, caps);
	
}

int	ft_identify_data_type(char const *c, int i, va_list args, int *len)
{
	void	*ptr;
	long	ptr_long;
	int		n;
	char	*str;

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
	{
		n = va_arg(args, int);
		ft_putnbr_fd(n , 1);
		if (n < 0)
		{
			len++;
			n = -n;
		}
		*(len) = *(len) + 1 + (n / 10);
	}
	// ptrs don't work yet, I think I need to set up hexadecimals first
	else if (c[i] == 'p')
	{
		ptr = va_arg(args, void *);
		ptr_long = (long)ptr;
		ft_putstr_fd("0x", 1);
		ft_puthex(ptr_long, 0);
		*len = (*len) + 14;
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
		ft_putnbr_unsigned(va_arg(args, unsigned int), 1);
		*(len) = *(len) + 1 + (n / 10);
	}
	else if (c[i] == 'x')
		ft_puthex(va_arg(args, int), 0);
	else if (c[i] == 'X')
		ft_puthex(va_arg(args, int), 1);
	return (i);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	va_list	args;
	int len;

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
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}