/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 12:31:43 by rboudwin         ###   ########.fr       */
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
#include "libft_ftprintf.h"
#include <stdio.h>

static int	ft_identify_data_type(const char *c, char *str, int i, va_list args)
{
	int	n;
	printf("We are trying to id data type, i is currently %d and c[i] is '%c'", i, c[i]);
	i++;
	if (c[i] == 'd')
	{
		n = va_arg(args, int);
		printf("n is %d \n", n);
		str = ft_strjoin(str, ft_itoa(n));
		return (i + 1);
	}

		//ft_fetch_int();
	//else if (c[i] == 'c')
	  // ft_fetch_char();

	return (i);
}
int ft_printf(const char *c, ...)
{
	int		i;
	int		start;
	int		len;
	char	*str;	
	va_list	args;
	//printf("%s", c);
	i = 0;
	start = 0;
	len = 0;
	str = malloc(1);
	str[0] = '\0';
	printf("%s \n", str);
	va_start(args, c);

printf("ft_printf launched, str is now '%s' \n", str);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
		{
			printf("we entered the percent loop \n");
			str = ft_strjoin(str, ft_substr(c, start, len)); 
			// If we decide to write logic to handle flags, we will need to wrap the next line with a
			// flag handler
			va_arg(args, char *);
			i = ft_identify_data_type(c, str, i, args);
		}
		else
			len++;
		i++;
	}
	printf("We exited format string loop, i is '%d' and str is '%s' \n", i, str);
	if (str[0] == '\0')
	{
		printf("We concluded str was never changed so we are just copying c \n");
		str = ft_strjoin(str, (char *)c);
	}
	printf("We are done checking to see if str still has a null terminator \n");
	ft_putstr_fd(str, 1);
	// printf("\n It works %s\n", str);
	// ft_putstr_fd(str, 1);
	va_end(args);
	free(str);
	return (ft_strlen(str));
}
