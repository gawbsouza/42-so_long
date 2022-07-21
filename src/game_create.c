/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:12:08 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 01:48:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_game	*new(void)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	if (game)
	{
		game->stat = NULL;
		game->map = NULL;
		game->gui = NULL;
		game->assets = NULL;
	}
	return (game);
}

static void	free_game(t_game **game)
{
	if (!game || !*game)
		return ;
	free((*game)->stat);
	assets_destroy((*game)->gui, &(*game)->assets);
	map_destroy(&(*game)->map);
	gui_destroy(&(*game)->gui);
	free(*game);
	*game = NULL;
}

t_game	*game_create(char *const *map, int bw, int bh, int bonus)
{
	t_game	*game;
	int		width;
	int		height;

	if (bw <= 0 && bh <= 0)
		return (NULL);
	game = new();
	if (game)
	{
		width = 0;
		height = 0;
		game->stat = stat_create(0, 0, 0, 0);
		game->map = map_create(map, bonus);
		if (game->map)
		{
			width = game->map->cols * bw;
			height = game->map->lines * bh;
		}
		game->gui = gui_create(width, height, "SO_LONG: GASOUZA");
		game->assets = assets_create(game->gui, bw, bh);
		if (!game->stat || !game->map || !game->gui || !game->assets)
			free_game(&game);
	}
	return (game);
}
