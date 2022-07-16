/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:50:16 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 13:43:01 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_imgset	*imgset_create(t_img *img)
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

void	imgset_add_img(t_imgset **imgset, t_img *img)
{
	t_list	*new;

	if (!imgset || !*imgset || !img)
		return ;
	new = ft_lstnew(img);
	if (new)
		ft_lstadd_back(&(*imgset)->list, new);
}

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
