/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:13:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/18 16:46:39 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
/*
int	main(void)
{
	int	a;
	int	*ptr;
	int	ft_return;
	int	printf_return;

	a = 3;
	ptr = &a;
	ft_printf("Let's try a string alone \n");
	ft_printf("Let's try a format string with an integer '%d' and a percent sign %% after \n", 42);
	ft_printf("%c%c%c\n", 'a', 'b', 'c');
	ft_return = ft_printf("'%u'\n", -10);
	printf_return = printf("'%u'\n", -10);
	printf("Return values - ft: '%d' printf: '%d'\n", ft_return, printf_return);
	ft_printf("Let's try three strings '%s' '%s' '%s'\n",
	  "one", "two", "three");
	ft_printf("Let's try some chars '%c' '%c'\n", 'a', 'b');
	ft_printf("Lets try to put 255 into hex '%x' '%X' \n", 255, 255);
	printf("Reference: '%x' '%X'\n", 255, 255);
	ft_printf("Let's try a pointer '%p'\n", ptr);
	printf("Reference: '%p'\n", ptr);
	ft_printf("Unsigned int '%u'\n", 2525);
	printf("Reference: '%u'\n", 2525);
	ft_printf("Null string test '%s' \n", NULL);
//	printf("Reference: '%s'\n", NULL);
	ft_return =	ft_printf("%p", "");
	printf("\n");
	printf_return = printf("%p", "");
	printf("\nFt_printf returns '%d' and printf returns '%d'"
	, ft_return, printf_return);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("%p\n", (void *)-14523);
	printf("%p\n", (void *)-14523);
//	ft_printf("Max long: %d", 9223372036854775807);
//	printf("Max long: %d", 9223372036854775807);
	
/*	
	if (argc == 1)
		ft_printf("Please enter arguments to be sent to the printf function");
	else if (argc == 2){
		printf("We concluded we have one argument 
		and it should print it as a string \n");
		ft_printf(argv[1]);}
	else if (argc == 3)
		ft_printf(argv[1], argv[2]);
	else
		ft_printf("Too many arguments for now.");
*/	
//}
