/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:38:08 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 03:49:09 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_assets	*new(int base_w, int base_h)
{
	t_assets	*assets;

	assets = (t_assets *) malloc(sizeof(t_assets));
	if (assets)
	{
		assets->base_w = base_w;
		assets->base_h = base_h;
		assets->monster = NULL;
		assets->player = NULL;
		assets->wall = NULL;
		assets->exit = NULL;
		assets->empty = NULL;
		assets->collect = NULL;
	}
	return (assets);
}

static t_imgset	*load_asset(t_assets *a, t_gui *g, char *file)
{
	t_imgset	*imgset;
	char		*img;

	imgset = NULL;
	if (a && g && file)
	{
		img = mlx_xpm_file_to_image(g->mlx, file, &a->base_w, &a->base_h);
		if (img)
			imgset = imgset_create(img);
	}
	return (imgset);
}

t_assets	*assets_create(t_gui *gui, int base_w, int base_h)
{
	t_assets	*assets;

	assets = NULL;
	if (gui && base_w > 0 && base_h > 0)
	{
		assets = new(base_w, base_h);
		if (assets)
		{
			assets->wall = load_asset(assets, gui, "./assets/wall.xpm");
			assets->empty = load_asset(assets, gui, "./assets/empty.xpm");
			assets->exit = load_asset(assets, gui, "./assets/exit.xpm");
			assets->collect = load_asset(assets, gui, "./assets/collect.xpm");
			assets->player = load_asset(assets, gui, "./assets/player.xpm");
			assets->monster = load_asset(assets, gui, "./assets/monster.xpm");
		}
	}
	return (assets);
}
