/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:37:07 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 03:45:02 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_imgset	*imgset_create(char *img)
{
	t_imgset	*imgset;

	imgset = NULL;
	if (img)
	{
		imgset = (t_imgset *) malloc(sizeof(t_imgset));
		if (imgset)
		{
			imgset->list = ft_lstnew(img);
			imgset->img = img;
		}
	}
	return (imgset);
}
