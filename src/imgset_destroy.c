/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:50:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:39:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imgset_destroy(t_imgset **imgset)
{
	t_list	*tmp;
	t_list	*tofree;

	if (!imgset || !*imgset || !(*imgset)->list)
		return ;
	tmp = (*imgset)->list;
	while (tmp->next)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
	}
	free(tmp->next);
	free(tmp);
	free(*imgset);
	*imgset = NULL;
}
