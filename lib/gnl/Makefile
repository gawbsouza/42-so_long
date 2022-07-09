# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 16:38:39 by gasouza           #+#    #+#              #
#    Updated: 2022/07/11 17:40:06 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)
AR		= ar -src
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
