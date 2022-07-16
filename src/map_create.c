/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:33:54 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 14:37:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_type(t_obj *obj, char type)
{
	if (!obj)
		return ;
	if (type == WALL_CHAR)
		obj->type = WALL;
	else if (type == COLLECT_CHAR)
		obj->type = COLLECT;
	else if (type == PLAYER_CHAR)
		obj->type = PLAYER;
	else if (type == EXIT_CHAR)
		obj->type = EXIT;
	else if (type == MONSTER_CHAR)
		obj->type = MONSTER;
	else
		obj->type = EMPTY;
}

static void	free_objs(size_t lines, t_obj **objs)
{
	while (objs && lines--)
		free(objs[lines]);
	free(objs);
}

static void	create_objs(t_map *map_obj, char *const *map)
{
	t_obj	**objs;
	size_t	lines;
	size_t	col;

	if (!map_obj)
		return ;
	objs = (t_obj **) malloc(map_obj->lines * sizeof(t_obj *));
	if (objs)
	{
		lines = 0;
		while (lines < map_obj->lines)
		{
			objs[lines] = (t_obj *) malloc(map_obj->cols * sizeof(t_obj));
			if (!objs[lines])
			{
				free_objs(lines, objs);
				break ;
			}
			col = map_obj->cols;
			while (col--)
				set_type(&objs[lines][col], map[lines][col]);
			lines++;
		}
	}
	map_obj->objs = objs;
}

static void	count_collects(t_map *map)
{
	size_t	l;
	size_t	c;

	l = 0;
	c = 0;
	if (!map)
		return ;
	map->collects = 0;
	while (l < map->lines)
	{
		c = 0;
		while (c < map->cols)
		{
			if (map->objs[l][c].type == COLLECT)
				map->collects++;
			c++;
		}
		l++;
	}
}

t_map	*map_create(char *const *map, int bonus)
{
	t_map	*map_obj;

	map_obj = NULL;
	if (map_check(map, bonus))
	{
		map_obj = (t_map *) malloc(sizeof(t_map));
		if (map_obj)
		{
			map_obj->lines = array_size(map);
			map_obj->cols = ft_strlen(*map);
			create_objs(map_obj, map);
			count_collects(map_obj);
		}
	}
	return (map_obj);
}
