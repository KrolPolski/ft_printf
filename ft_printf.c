/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 15:38:38 by rboudwin         ###   ########.fr       */
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

int	ft_identify_data_type(char const *c, int i, va_list args)
{
	int n;

	i++;
	if (c[i] == 'd')
	{
		n = va_arg(args, int);
		ft_putnbr_fd(n, 1);
	}
	if (c[i] == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
	}
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