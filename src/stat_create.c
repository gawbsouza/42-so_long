/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:27:23 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 01:38:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_stat	*stat_create(int moves, int collects, int dead, int end)
{
	t_stat	*st;

	st = (t_stat *) malloc(sizeof(t_stat));
	if (st)
	{
		st->moves = moves;
		st->collects = collects;
		st->dead = dead;
		st->end = end;
	}
	return (st);
}
