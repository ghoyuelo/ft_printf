# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 17:35:59 by ghoyuelo          #+#    #+#              #
#    Updated: 2021/11/23 15:09:32 by ghoyuelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c\
		  ft_utils1.c\
		  ft_utils2.c\
		  ft_itoa.c\
		  ft_unitoa.c\

OBJS	= $(SRCS:%.c=%.o)
		  
INCS	= ft_printf.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBC	= ar rcs

RM		= -rm -f

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(INCS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c .o
