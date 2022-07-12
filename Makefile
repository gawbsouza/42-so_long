# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 19:52:48 by gasouza           #+#    #+#              #
#    Updated: 2022/07/12 20:53:26 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -g -Wall -Werror -Wextra
LIBS	= ft gnl 
LIBS_D	= lib
LIBS_A	= $(addsuffix .a, $(addprefix $(LIBS_D)/,$(LIBS)))
SRCS	= utils.c map_check.c map_load_file.c
SRCS_D	= src
OBJS	= $(subst .c,.o,$(addprefix $(SRCS_D)/,$(SRCS)))
RM		= rm -rf
TESTS	= map_check.c map_load_file.c
TESTS_D	= tests
TESTS_F = $(TESTS:.c=_test)
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
	$(CC) $(CFLAGS)	$(addprefix -I$(LIBS_D)/,$(LIBS)) -c $< -o $@

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
%_test: $(TESTS_D)/%.o $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $< $(addprefix -L$(LIBS_D)/,$(LIBS)) \
		$(addprefix -l,$(LIBS)) -o $(TESTS_D)/$@
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
