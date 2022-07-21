/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:02:53 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 02:07:05 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_destroy(t_game **game)
{
	if (!game || !*game)
		return ;
	free((*game)->stat);
	map_destroy(&(*game)->map);
	assets_destroy((*game)->gui, &(*game)->assets);
	gui_destroy(&(*game)->gui);
	free(*game);
	*game = NULL;
}
