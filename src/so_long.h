/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:17:00 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 13:42:47 by gasouza          ###   ########.fr       */
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

# define BONUS 0

# define WALL_CHAR '1'
# define EMPTY_CHAR '0'
# define COLLECT_CHAR 'C'
# define EXIT_CHAR 'E'
# define PLAYER_CHAR 'P'
# define MONSTER_CHAR 'M'

typedef enum e_type
{
	WALL,
	EMPTY,
	COLLECT,
	EXIT,
	PLAYER,
	MONSTER
}	t_type;

typedef struct s_img
{
	void	*content;
	int		width;
	int		height;
}	t_img;

typedef struct s_imgset
{
	t_img	*img;
	t_list	*list;
}	t_imgset;

typedef struct s_obj
{
	t_type		type;
	t_imgset	*imgs;
}	t_obj;

typedef struct s_map
{
	t_obj	**objs;
	size_t	lines;
	size_t	cols;
}	t_map;

char		**map_load_file(const char *file);
int			map_check(char *const *map, int bonus);
t_map		*map_create(char *const *map, int bonus);
size_t		array_size(char *const *array);
size_t		array_objs_size(t_obj **array);
void		free_array(char **array);
t_imgset	*imgset_create(t_img *img);
void		imgset_add_img(t_imgset **imgset, t_img *img);
void		imgset_spin(t_imgset **imgset);
void		imgset_destroy(t_imgset **imgset);

#endif
