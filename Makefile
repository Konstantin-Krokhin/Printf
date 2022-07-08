# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 21:37:09 by kokrokhi          #+#    #+#              #
#    Updated: 2022/07/07 21:37:11 by kokrokhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= printf.c
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs	$(NAME) $(OBJS)
clean: 
				$(RM)	$(OBJS)

fclean:			clean
				$(RM)	$(NAME)				
re: fclean all