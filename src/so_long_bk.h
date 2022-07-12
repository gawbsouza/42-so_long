/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:17:00 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/12 15:10:51 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include <stddef.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define WALL_CHAR '1'
# define EMPTY_CHAR '0'
# define COLLECT_CHAR 'C'
# define EXIT_CHAR 'E'
# define PLAYER_CHAR 'P'

/* typedef struct s_list */
/* { */
/* 	void			*data; */
/* 	struct s_list	*next; */
/* }	t_list; */

/* typedef struct s_pos */
/* { */
/* 	int	x; */
/* 	int	y; */
/* }	t_pos; */

/* typedef struct s_obj */
/* { */
/* 	int		type; */
/* 	t_list	*imgs; */
/* 	t_pos	pos; */
/* }	t_obs; */

/* typedef struct s_map */
/* { */
/* 	t_obj	**objs; */
/* 	int		lines; */
/* 	int		columns; */
/* }	t_map; */

/* t_obj	*map_obj_get(t_map *map, int x, int y); */
/* int		map_obj_set(t_map map, t_obj obj, int x, int y); */
/* int		map_obj_destroy(t_map map, t_obj obj, t_pos pos); */
char	**map_load_file(const char *file);
int		map_check(char *const *map);
size_t	array_size(char *const *array);
void	free_array(char **array);

#endif
