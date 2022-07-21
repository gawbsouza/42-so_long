/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:14:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 13:30:27 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	force_exit(t_game *game)
{
	if (!game)
		return (0);
	game->stat->end = TRUE;
	game->stat->dead = TRUE;
	return (0);
}

static int	loop_hook(t_game *game)
{
	if (game->stat->end == TRUE)
	{
		if (game->stat->dead)
			ft_printf("\n\033[1;33m :: GAME OVER :: \033[;0m\n");
		else
			ft_printf("\n\033[1;36m :: YOU WIN!! :: \033[;0m\n");
		mlx_loop_end(game->gui->mlx);
	}
	return (0);
}

static void	show(t_game *game)
{
	if (!game)
		return ;
	window_draw(game->gui, game->assets, game->map);
	ft_printf("\r\033[1;35m MOVES:\033[;0m %d   ", game->stat->moves);
}

static int	key_hook(int key, t_game *game)
{
	if (key == XK_Escape)
		force_exit(game);
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		if (key == XK_w)
			player_move(TO_UP, game->map, game->stat);
		if (key == XK_s)
			player_move(TO_DOWN, game->map, game->stat);
		if (key == XK_d)
			player_move(TO_RIGHT, game->map, game->stat);
		if (key == XK_a)
			player_move(TO_LEFT, game->map, game->stat);
		show(game);
	}
	return (0);
}

int	game_loop(t_game *game)
{
	if (!game)
		return (1);
	show(game);
	mlx_loop_hook(game->gui->mlx, loop_hook, game);
	mlx_key_hook(game->gui->win, key_hook, game);
	mlx_hook(game->gui->win, 17, 0, force_exit, game);
	mlx_loop(game->gui->mlx);
	game_destroy(&game);
	return (0);
}
