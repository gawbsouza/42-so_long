/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:52:21 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 17:56:39 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TYPES_H
# define SO_TYPES_H

typedef enum e_type
{
	WALL,
	EMPTY,
	COLLECT,
	EXIT,
	PLAYER,
	MONSTER
}	t_type;

typedef struct s_img
{
	void	*content;
	int		width;
	int		height;
}	t_img;

typedef struct s_imgset
{
	t_img	*img;
	t_list	*list;
}	t_imgset;

typedef struct s_obj
{
	t_type		type;
	t_imgset	*imgs;
}	t_obj;

typedef struct s_map
{
	t_obj	**objs;
	size_t	lines;
	size_t	cols;
	int		collects;
}	t_map;

#endif
