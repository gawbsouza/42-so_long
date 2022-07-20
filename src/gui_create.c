/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:26:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 20:54:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gui	*gui_create(int width, int height, char *title)
{
	t_gui	*gui;

	if (width <= 0 || height <= 0 || !title)
		return (NULL);
	gui = (t_gui *) malloc(sizeof(t_gui));
	if (gui)
	{
		gui->mlx = mlx_init();
		if (gui->mlx)
		{
			gui->win = mlx_new_window(gui->mlx, width, height, title);
			if (!gui->win)
			{
				mlx_destroy_display(gui->mlx);
				free(gui->mlx);
			}
		}
		else
		{
			free(gui);
			gui = NULL;
		}
	}
	return (gui);
}
