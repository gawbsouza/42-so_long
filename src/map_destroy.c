/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:14:49 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/18 17:23:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_destroy(t_map **map)
{
	size_t	l = 0;

	if (!map || !*map)
		return ;
	l = (*map)->lines;
	while (l--)
		free((*map)->objs[l]);
	free((*map)->objs);
	free(*map);
	*map = NULL;
}
