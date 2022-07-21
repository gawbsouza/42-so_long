/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:33:54 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 12:39:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_invalid_char(char *const *map, int bonus)
{
	char	*str;

	while (map && *map)
	{
		str = *map;
		while (str && *str)
		{
			if (bonus && *str == MONSTER_CHAR)
				str++;
			else if (*str == WALL_CHAR)
				str++;
			else if (*str == EMPTY_CHAR)
				str++;
			else if (*str == COLLECT_CHAR)
				str++;
			else if (*str == EXIT_CHAR)
				str++;
			else if (*str == PLAYER_CHAR)
				str++;
			else
				return (TRUE);
		}
		map++;
	}
	return (FALSE);
}

static int	has_minimum_size(char *const *map)
{
	size_t	columns;
	size_t	lines;

	columns = 0;
	lines = 0;
	while (map && *map)
	{
		if (columns == 0)
			columns = ft_strlen(*map);
		if (ft_strlen(*map) != columns)
			return (FALSE);
		lines++;
		map++;
	}
	return (columns + lines >= 8);
}

static int	has_minimum_components(char *const *map)
{
	int	collect;
	int	exit;
	int	player;

	collect = 0;
	exit = 0;
	player = 0;
	while (map && *map)
	{
		if (ft_strrchr(*map, COLLECT_CHAR))
			collect++;
		if (ft_strrchr(*map, EXIT_CHAR))
			exit++;
		if (ft_strrchr(*map, PLAYER_CHAR))
			player++;
		map++;
	}
	return (collect > 0 && exit > 0 && player == 1);
}

static int	has_wall_surrounded(char *const *map)
{
	size_t	last_line;
	size_t	cols;
	size_t	lines;

	lines = array_size(map);
	if (lines < 3)
		return (FALSE);
	last_line = lines - 1;
	cols = ft_strlen(*map);
	while (cols--)
	{
		if (map[0][cols] != WALL_CHAR || map[last_line][cols] != WALL_CHAR)
			return (FALSE);
	}
	cols = ft_strlen(*map);
	while (lines--)
	{
		if (lines == 0 || lines == last_line)
			continue ;
		if (map[lines][0] != WALL_CHAR || map[lines][cols - 1] != WALL_CHAR)
			return (FALSE);
	}
	return (TRUE);
}

int	map_check(char *const *map, int bonus)
{
	if (map == NULL)
		return (FALSE);
	if (has_invalid_char(map, bonus))
	{
		ft_printf("Invalid Map: invalid char found.\n");
		return (FALSE);
	}
	if (!has_minimum_size(map))
	{
		ft_printf("Invalid Map: invalid size.\n");
		return (FALSE);
	}
	if (!has_wall_surrounded(map))
	{
		ft_printf("Invalid Map: not surrounded by walls.\n");
		return (FALSE);
	}
	if (!has_minimum_components(map))
	{
		ft_printf("Invalid Map: not enough components.\n");
		return (FALSE);
	}
	return (TRUE);
}
