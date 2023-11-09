# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:21:42 by rboudwin          #+#    #+#              #
#    Updated: 2023/11/09 16:28:56 by rboudwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o) \
		libft.a

TEST_SRCS = ft_tests.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS) libft.a 
	ar -rc $(NAME) $(OBJS) libftprintf.a

test: ft_tests.o libft.a 
	cc $(CFLAGS) $(OBJS) ft_tests.o libft.a -o test
# bonus : .bonus
	
# .bonus : $(OBJS) $(BONUS_OBJS)
#		touch .bonus;
#		ar -rc $(NAME) $(BONUS_OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) # .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
