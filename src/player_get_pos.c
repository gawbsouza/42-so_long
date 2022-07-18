/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:10:36 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/18 17:43:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	*player_get_pos(t_map *map)
{
	t_pos	*pos;
	size_t	l;
	size_t	c;

	pos = NULL;
	l = 0;
	while (map && l < map->lines && !pos)
	{
		c = 0;
		while (c < map->lines)
		{
			if (map->objs[l][c].type == PLAYER)
			{
				pos = (t_pos *) malloc(sizeof(t_pos));
				if (!pos)
					return (NULL);
				pos->x = c;
				pos->y = l;
				break ;
			}
			c++;
		}
		l++;
	}
	return (pos);
}
