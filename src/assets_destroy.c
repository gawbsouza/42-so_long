/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:35 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 17:22:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assets_destroy(t_gui *gui, t_assets **assets)
{
	if (!assets || !*assets)
		return ;
	mlx_destroy_image(gui->mlx, (*assets)->empty->img);
	mlx_destroy_image(gui->mlx, (*assets)->wall->img);
	mlx_destroy_image(gui->mlx, (*assets)->player->img);
	mlx_destroy_image(gui->mlx, (*assets)->collect->img);
	mlx_destroy_image(gui->mlx, (*assets)->exit->img);
	mlx_destroy_image(gui->mlx, (*assets)->monster->img);
	imgset_destroy(&(*assets)->empty);
	imgset_destroy(&(*assets)->wall);
	imgset_destroy(&(*assets)->player);
	imgset_destroy(&(*assets)->collect);
	imgset_destroy(&(*assets)->monster);
	imgset_destroy(&(*assets)->exit);
	free(*assets);
	*assets = NULL;
}
