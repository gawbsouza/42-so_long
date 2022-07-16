/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_add_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:38:10 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:38:34 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imgset_add_img(t_imgset **imgset, t_img *img)
{
	t_list	*new;

	if (!imgset || !*imgset || !img)
		return ;
	new = ft_lstnew(img);
	if (new)
		ft_lstadd_back(&(*imgset)->list, new);
}
