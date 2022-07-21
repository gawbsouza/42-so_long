/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:28:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 13:06:25 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_type t, t_pos *p, t_gui *g, t_assets *a)
{
	char	*img;

	if (!g || !p || !a)
		return ;
	if (t == WALL)
		img = a->wall->img;
	if (t == EMPTY)
		img = a->empty->img;
	if (t == PLAYER)
		img = a->player->img;
	if (t == MONSTER)
		img = a->monster->img;
	if (t == EXIT)
		img = a->exit->img;
	if (t == COLLECT)
		img = a->collect->img;
	mlx_put_image_to_window(g->mlx, g->win, img, p->x, p->y);
}

void	window_draw(t_gui *gui, t_assets *assets, t_map *map)
{
	size_t	c;
	size_t	l;
	t_pos	pos;

	if (!gui || !assets || !map)
		return ;
	l = 0;
	pos.y = 0;
	while (l < map->lines)
	{
		c = 0;
		pos.x = 0;
		while (c < map->cols)
		{
			draw_image(map->objs[l][c].type, &pos, gui, assets);
			pos.x += assets->base_w;
			c++;
		}
		pos.y += assets->base_h;
		l++;
	}
}
