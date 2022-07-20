# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 19:52:48 by gasouza           #+#    #+#              #
#    Updated: 2022/07/20 16:20:18 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -g -Wall -Werror -Wextra
LIBS	= ft gnl 
MLXFLAGS= -lmlx -lX11 -lXext
LIBS_D	= lib
LIBS_A	= $(addsuffix .a, $(addprefix $(LIBS_D)/,$(LIBS)))
SRCS	= map_check.c		\
		  map_load_file.c	\
		  map_create.c		\
		  map_destroy.c		\
		  imgset_create.c	\
		  imgset_add_img.c	\
		  imgset_spin.c		\
		  imgset_destroy.c	\
		  array_size.c		\
		  array_objs_size.c	\
		  free_array.c		\
		  player_get_pos.c	\
		  player_move.c		\
		  assets_create.c
SRCS_D	= src
OBJS	= $(subst .c,.o,$(addprefix $(SRCS_D)/,$(SRCS)))
RM		= rm -rf
TESTS_D	= tests
TESTS_F = $(SRCS:.c=_test)
TFLAGS	= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME): $(LIBS_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(addprefix -L$(LIBS_D)/,$(LIBS)) \
		$(addprefix -l,$(LIBS)) -o $@

# Make libraries
%.a: 
	make -C $*

# Make objects
%.o: %.c 
	$(CC) $(CFLAGS)	$(addprefix -I$(LIBS_D)/,$(LIBS)) $(MLXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) main

re: fclean main

# TESTS

# Run tests
tests: $(TESTS_F) 
	clear
	$(foreach cmd, $(addprefix ./$(TESTS_D)/,$(TESTS_F)), $(cmd); )	
	
# Make tests
%_test: $(TESTS_D)/%.o $(LIBS_A) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $< $(addprefix -L$(LIBS_D)/,$(LIBS)) \
		$(addprefix -l,$(LIBS)) $(MLXFLAGS) -o $(TESTS_D)/$@
ifeq (run, $(filter run, $(MAKECMDGOALS)))
	clear
ifeq (valgrind, $(filter valgrind, $(MAKECMDGOALS)))
	$(TFLAGS) $(TESTS_D)/$@
else
	$(TESTS_D)/$@
endif
endif

clean_tests:
	$(RM) $(addprefix $(TESTS_D)/,$(TESTS_F))

.PHONY : all clean fclean re test clean_tests run valgrind
