/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:13:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 16:22:05 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a;
	int *ptr;
	
	a = 3;
	ptr = &a;
	ft_printf("Let's try a string alone \n");
	ft_printf("Let's try a format string with an integer '%d' and a percent sign %% after \n", 42);
	ft_printf("Let's try three strings '%s' '%s' '%s'\n", "one", "two", "three");
	ft_printf("Let's try some chars '%c' '%c'\n", 'a', 'b');
	ft_printf("Lets try to put 255 into hex '%x' '%X' \n", 255, 255);
	ft_printf("Let's try a pointer '%p'", ptr);
	/*
	if (argc == 1)
		ft_printf("Please enter arguments to be sent to the printf function");
	else if (argc == 2){
		printf("We concluded we have one argument and it should print it as a string \n");
		ft_printf(argv[1]);}
	else if (argc == 3)
		ft_printf(argv[1], argv[2]);
	else
		ft_printf("Too many arguments for now.");
		*/
}
