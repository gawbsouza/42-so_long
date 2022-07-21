/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:02:09 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 01:11:49 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gui_destroy(t_gui **gui)
{
	if (!gui || !*gui)
		return ;
	if ((*gui)->win && (*gui)->mlx)
		mlx_destroy_window((*gui)->mlx, (*gui)->win);
	if ((*gui)->mlx)
	{
		mlx_destroy_display((*gui)->mlx);
		free((*gui)->mlx);
	}
	free(*gui);
	*gui = NULL;
}
