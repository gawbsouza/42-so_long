/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_spin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:38:45 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:39:47 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imgset_spin(t_imgset **imgset)
{
	t_list	*tmp;

	if (!imgset || !*imgset || !(*imgset)->img)
		return ;
	if (ft_lstsize((*imgset)->list) <= 1)
		return ;
	tmp = (*imgset)->list;
	while (tmp->next && tmp->content != (*imgset)->img)
		tmp = tmp->next;
	if (tmp->next)
		(*imgset)->img = tmp->next->content;
	else
		(*imgset)->img = (*imgset)->list->content;
}
