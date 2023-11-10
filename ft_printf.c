/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:55 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/10 12:16:46 by rboudwin         ###   ########.fr       */
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
#include "libft.h"

static void	ft_identify_data_type(const char *c, int i)
{
	if (c[++i] == 'd')
		ft_fetch_int();
	else if (c[i] == 'c')
	   ft_fetch_char();

	return (i);
}
int ft_printf(const char *c, ...)
{
	int		i;
	int		start;
	int		len;
	char	str[1];

	i = 0;
	start = 0;
	len = 0;
	str[0] = '\0';

	while (c[i] != '\0')
	{
		if (c[i] == '%')
		{
			str = ft_strjoin(str, ft_substr(c, start, len); 
			i = ft_identify_data_type(c, i);
		}
		else
			len++;
		i++;
	}



	return (ft_strlen(str));
}
