# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 19:52:48 by gasouza           #+#    #+#              #
#    Updated: 2022/07/21 14:34:49 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -g -Wall -Werror -Wextra
RM			= rm -rf

LIBS_D		= lib

MLX			= -lmlx -lX11 -lXext
LIBFT_D 	= $(LIBS_D)/libft
LIBFT_L		= -L$(LIBFT_D) -lft
LIBFT_A 	= $(LIBFT_D)/libft.a
GNL_D 		= $(LIBS_D)/gnl
GNL_L		= -L$(GNL_D) -lgnl
GNL_A 		= $(GNL_D)/libgnl.a
FTPRINTF_D	= $(LIBS_D)/ft_printf
FTPRINTF_L	= -L$(FTPRINTF_D) -lftprintf
FTPRINTF_A 	= $(FTPRINTF_D)/libftprintf.a

LIBS_L		= $(LIBFT_L) $(GNL_L) $(FTPRINTF_L)
LIBS_I		= -I$(LIBFT_D) -I$(GNL_D) -I$(FTPRINTF_D)
LIBS_A		= $(LIBFT_A) $(GNL_A) $(FTPRINTF_A)

SRCS_D		= src
SRCS		= map_check.c		map_load_file.c		map_create.c		\
		  	map_destroy.c		imgset_create.c		imgset_add_img.c	\
		  	imgset_spin.c		imgset_destroy.c	array_size.c		\
		  	array_objs_size.c	free_array.c		player_get_pos.c	\
		  	player_move.c		assets_create.c		assets_destroy.c	\
		  	gui_create.c		gui_destroy.c		window_draw.c		\
		  	game_create.c		stat_create.c		game_destroy.c		\
		  	so_long.c			game_init.c			game_loop.c			\
		  	map_valid_file_ext.c

OBJS		= $(subst .c,.o,$(addprefix $(SRCS_D)/,$(SRCS)))

all: $(NAME)

$(NAME): $(LIBS_A) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_L) $(MLX) -o $@

# Make libraries
$(LIBFT_A): 
	make -C $(LIBFT_D) 
	
$(GNL_A): 
	make -C $(GNL_D) 

$(FTPRINTF_A): 
	make -C $(FTPRINTF_D) 

# Make objs
%.o: %.c 
	$(CC) $(CFLAGS)	$(LIBS_L) $(MLX) -c $< $(LIBS_I) -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_D)
	make clean -C $(GNL_D)
	make clean -C $(FTPRINTF_D)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_D)
	make fclean -C $(GNL_D)
	make fclean -C $(FTPRINTF_D)

re: fclean all

run:
	./$(NAME) maps/default.ber

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/01.ber

.PHONY : all clean fclean re run valgrind 
