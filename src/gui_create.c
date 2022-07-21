/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:26:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 01:13:28 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_size(void *mlx, int width, int height)
{
	int	d_width;
	int	d_height;

	if (mlx && width > 0 && height > 0)
	{
		if (mlx_get_screen_size(mlx, &d_width, &d_height))
		{
			if (width <= d_width && height <= d_height)
				return (TRUE);
		}
	}
	return (FALSE);
}

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
		{
			if (is_valid_size(gui->mlx, width, height))
				gui->win = mlx_new_window(gui->mlx, width, height, title);
			else
				ft_printf("Map is too big to render.\n");
		}
		if (!gui->mlx || !gui->win)
			gui_destroy(&gui);
	}
	return (gui);
}
