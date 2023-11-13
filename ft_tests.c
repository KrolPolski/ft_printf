/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:13:53 by rboudwin          #+#    #+#             */
/*   Updated: 2023/11/13 15:14:25 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Let's try a string alone");
	ft_printf("Let's try a format string with an integer '%d' and some text after", 42);
//	ft_printf("Let's try three strings '%s'", "one");
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
