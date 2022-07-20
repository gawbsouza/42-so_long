/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:52:21 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 16:48:05 by gasouza          ###   ########.fr       */
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

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

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

typedef struct s_stat
{
	int	collects;
	int	moves;
	int	dead;
	int	end;
}	t_stat;

typedef struct s_map
{
	t_obj	**objs;
	size_t	lines;
	size_t	cols;
	int		collects;
}	t_map;

typedef struct s_gui
{
	void	*mlx;
	void	*win;
}	t_gui;

typedef struct s_assets
{
	int			base_w;
	int			base_h;
	t_imgset	*player;
	t_imgset	*monster;
	t_imgset	*empty;
	t_imgset	*exit;
	t_imgset	*collect;
	t_imgset	*wall;
}	t_assets;

#endif
