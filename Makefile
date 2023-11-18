# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:21:42 by rboudwin          #+#    #+#              #
#    Updated: 2023/11/18 18:11:44 by rboudwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_handlenumbers.c ft_pointers.c libft/ft_putchar_fd.c \
		libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c

OBJS = $(SRCS:.c=.o) 

NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJS) 
	$(MAKE) -C libft/ bonus 
	cp libft/libft.a ./libftprintf.a
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
