/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:09:10 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 13:05:13 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, const char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		if (argc < 2)
			ft_printf("Please, inform a map.\n");
		else
			ft_printf("Inform only one map.\n");
		return (1);
	}
	game = game_init(argv[1]);
	return (game_loop(game));
}
