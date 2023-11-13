/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 16:25:56 by rboudwin         ###   ########.fr       */
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

static void ft_puthex(int n, int caps)
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
	if (n >= 16)
	{
		ft_puthex(n / 16, caps);
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

int	ft_identify_data_type(char const *c, int i, va_list args)
{
	void *ptr;

	i++;
	if (c[i] == '%')
		ft_putchar_fd('%', 1);
	else if (c[i] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c[i] == 'd' || c[i] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	// ptrs don't work yet, I think I need to set up hexadecimals first
	else if (c[i] == 'p')
	{
		ptr = va_arg(args, void *);
		write(1, ptr, sizeof(void *));
	}
	else if (c[i] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
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
			i = ft_identify_data_type(c, i, args);
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