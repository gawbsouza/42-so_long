/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:52:03 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/19 16:19:19 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_moviment(char dir, t_pos *p, t_map *map)
{
	if (!p || !map)
		return (FALSE);
	if (dir == TO_LEFT && p->x > 0)
		return (TRUE);
	if (dir == TO_RIGHT && p->x < map->cols - 1)
		return (TRUE);
	if (dir == TO_UP && p->y > 0)
		return (TRUE);
	if (dir == TO_DOWN && p->y < map->lines - 1)
		return (TRUE);
	return (FALSE);
}

static void	change_position(t_obj *old, t_obj *new, t_map *map, t_stat *st)
{
	if (!old || !new || !map || !st)
		return ;
	if (new->type == WALL)
		return ;
	if (new->type == COLLECT)
	{
		new->type = PLAYER;
		st->collects++;
	}
	else if (new->type == MONSTER)
	{
		st->dead = 1;
		st->end = 1;
	}
	else if (new->type == EXIT && map->collects <= st->collects)
	{
		st->dead = 0;
		st->end = 1;
	}
	old->type = EMPTY;
	st->moves++;
}

void	player_move(char dir, t_map *map, t_stat *st)
{
	t_pos	*player_pos;
	t_obj	*player_obj;
	t_obj	*new_obj;

	if (!map || !st)
		return ;
	player_pos = player_get_pos(map);
	if (!player_pos || !is_valid_moviment(dir, player_pos, map))
		return ;
	player_obj = &map->objs[player_pos->y][player_pos->x];
	if (dir == TO_LEFT)
		new_obj = &map->objs[player_pos->y][player_pos->x - 1];
	if (dir == TO_RIGHT)
		new_obj = &map->objs[player_pos->y][player_pos->x + 1];
	if (dir == TO_UP)
		new_obj = &map->objs[player_pos->y + 1][player_pos->x];
	if (dir == TO_DOWN)
		new_obj = &map->objs[player_pos->y - 1][player_pos->x];
	free(player_pos);
	change_position(player_obj, new_obj, map, st);
}
