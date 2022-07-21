/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:02:09 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 21:20:53 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gui_destroy(t_gui **gui)
{
	if (!gui || !*gui)
		return ;
	mlx_destroy_window((*gui)->mlx, (*gui)->win);
	mlx_destroy_display((*gui)->mlx);
	free((*gui)->mlx);
	free(*gui);
	*gui = NULL;
}
