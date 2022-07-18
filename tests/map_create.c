/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:54:07 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/18 17:16:48 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../src/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

void	print_map(const t_map *map)
{
	t_type type;
	size_t	l;
	size_t	c;

	l = 0;
	while (l < map->lines)
	{
		printf(" | ");
		c = 0;
		while (c < map->cols)
		{
			type = map->objs[l][c].type;
			if (type == WALL)
				printf("%7s", "WALL");
			if (type == EMPTY)
				printf("%7s", "EMPTY");
			if (type == MONSTER)
				printf("%7s", "MONSTER");
			if (type == COLLECT)
				printf("%7s", "COLLECT");
			if (type == PLAYER)
				printf("%7s", "PLAYER");
			if (type == EXIT)
				printf("%7s", "EXIT");
			printf(" | ");
			c++;
		}
		printf("\n");
		l++;
	}
}

size_t	count_obj_type(const t_map *map, t_type type)
{
	size_t	count = 0;
	size_t	l = 0;
	size_t	c = 0;

	if (map)
	{
		while (l < map->lines)
		{
			c = 0;
			while (c < map->cols)
			{
				if (map->objs[l][c].type == type)
					count++;
				c++;
			}
			l++;
		}
	}
	return (count);
}

void	free_objs(size_t lines, t_obj **objs)
{
	while (objs && lines--)
		free(objs[lines]);
	free(objs);
}

void test_map(void)
{
	char *map[] = {"1111", "1MC1", "10P1", "1EC1", "1111", NULL};
	t_map *gmap = map_create(map, TRUE);

	result("map lines", gmap->lines == 5);
	result("map columns", gmap->cols == 4);
	result("map obj wall positon", gmap->objs[0][0].type == WALL);
	result("map obj monster positon", gmap->objs[1][1].type == MONSTER);
	result("map obj collect positon", gmap->objs[1][2].type == COLLECT);
	result("map obj empty positon", gmap->objs[2][1].type == EMPTY);
	result("map obj player positon", gmap->objs[2][2].type == PLAYER);
	result("map obj exit positon", gmap->objs[3][1].type == EXIT);
	result("map count obj wall", count_obj_type(gmap, WALL) == 14);
	result("map count obj empty", count_obj_type(gmap, EMPTY) == 1);
	result("map count obj monster", count_obj_type(gmap, MONSTER) == 1);
	result("map count obj exit", count_obj_type(gmap, EXIT) == 1);
	result("map count obj player", count_obj_type(gmap, PLAYER) == 1);
	result("map count obj collect", gmap->collects == 2);
	free_objs(gmap->lines, gmap->objs);
	free(gmap);
}

int	main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_map();

	printf("\n");
	return (0);
}
