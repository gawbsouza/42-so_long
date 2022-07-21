/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:26:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 15:31:16 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_gui	*new(void)
{
	t_gui	*gui;

	gui = (t_gui *) malloc(sizeof(t_gui));
	if (gui)
	{
		gui->mlx = NULL;
		gui->win = NULL;
	}
	return (gui);
}

t_gui	*gui_create(int width, int height, char *title)
{
	t_gui	*gui;

	if (width <= 0 || height <= 0 || !title)
		return (NULL);
	gui = new();
	if (gui)
	{
		gui->mlx = mlx_init();
		if (gui->mlx)
			gui->win = mlx_new_window(gui->mlx, width, height, title);
		if (!gui->mlx || !gui->win)
			gui_destroy(&gui);
	}
	return (gui);
}
