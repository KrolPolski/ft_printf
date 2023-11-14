# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:21:42 by rboudwin          #+#    #+#              #
#    Updated: 2023/11/14 16:31:33 by rboudwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_handlenumbers.c ft_pointers.c

OBJS = $(SRCS:.c=.o) 

TEST_SRCS = ft_tests.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS) libft.a 
	ar -rc $(NAME) $(OBJS) libft/libft.a libftprintf.a

test: $(NAME) ft_tests.o libft.a 
	cc $(CFLAGS) $(OBJS) ft_tests.o libft.a -o test

libft.a : 
	$(MAKE) -C libft/ bonus 
	cp libft/libft.a ./libftprintf.a
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) # .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean libft.a fclean re
