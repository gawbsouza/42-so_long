/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:22:57 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 13:16:11 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game_init(const char *file)
{
	t_game		*game;
	char		**mapstr;

	if (!map_valid_file_ext(file))
	{
		ft_printf("Invalid Map: invalid extension.\n");
		return (NULL);
	}
	mapstr = map_load_file(file);
	if (!mapstr)
		return (NULL);
	game = game_create(mapstr, SPRITE_WIDTH, SPRITE_HEIGHT, BONUS);
	free_array(mapstr);
	return (game);
}
