/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:28:15 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 22:54:04 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_image(t_type t, t_pos *p, t_gui *g, t_assets *a)
{
	void	*img;

	if (!g || !p || !a)
		return (FALSE);
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
	return (mlx_put_image_to_window(g->mlx, g->win, img, p->x, p->y));
}

int	window_draw(t_gui *gui, t_assets *assets, t_map *map)
{
	size_t	c;
	size_t	l;
	t_pos	pos;

	if (!gui || !assets || !map || !mlx_clear_window(gui->mlx, gui->win))
		return (FALSE);
	l = 0;
	pos.y = 0;
	while (l < map->lines)
	{
		c = 0;
		pos.x = 0;
		while (c < map->cols)
		{
			if (!draw_image(map->objs[l][c].type, &pos, gui, assets))
				return (FALSE);
			pos.x += assets->base_w;
			c++;
		}
		pos.y += assets->base_h;
		l++;
	}
	return (TRUE);
}
