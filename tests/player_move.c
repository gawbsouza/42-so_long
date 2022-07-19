/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:37:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/19 16:16:51 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include <stdio.h>

void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

t_stat *new_stat(int c, int m, int d, int e)
{
	t_stat *st;
	st = (t_stat *) malloc(sizeof(t_stat));
	if (st)
	{
		st->collects = c;
		st->moves = m;
		st->dead = d;
		st->end = e;
	}
	return (st);

}

int	stat_cmp(const t_stat *st, int c, int m, int d, int e)
{
	return (st && st->collects == c && \
			st->moves == m && st->dead == d && \
			st->end == e);
}


int map_cmp(const t_map *m1, const t_map *m2)
{
	size_t c;
	size_t l;

	if (!m1 || !m2)
		return (FALSE);
	if (m1->cols != m2->cols || m1->lines != m2->lines)
		return (FALSE);
	l = 0;
	while (l < m1->lines)
	{
		c = 0;
		while (c < m1->cols)
		{
			if (m1->objs[l][c].type != m2->objs[l][c].type)
				return (FALSE);
			c++;
		}
		l++;
	}
	return (TRUE);
}

void	test_move_to_wall()
{
	t_stat *st = new_stat(0, 0, 0, 0);
	char *mapstr1[] = {"11111", "1PCE1", "11111", NULL};
	char *mapstr2[] = {"11111", "1ECP1", "11111", NULL};
	t_map *map1 = map_create(mapstr1, FALSE);
	t_map *map2 = map_create(mapstr2, FALSE);
	t_map *mapcmp1 = map_create(mapstr1, FALSE);
	t_map *mapcmp2 = map_create(mapstr2, FALSE);

	player_move(TO_LEFT, map1, st);
	result("left: to wall : status", stat_cmp(st, 0, 0, 0, 0));
	result("left: to wall : objs", map_cmp(map1, mapcmp1));
	
	player_move(TO_UP, map1, st);
	result("up: to wall : status", stat_cmp(st, 0, 0, 0, 0));
	result("up: to wall : objs", map_cmp(map1, mapcmp1));

	player_move(TO_RIGHT, map2, st);
	result("right: to wall : status", stat_cmp(st, 0, 0, 0, 0));
	result("right: to wall : objs", map_cmp(map2, mapcmp2));
	
	player_move(TO_DOWN, map2, st);
	result("down: to wall : status", stat_cmp(st, 0, 0, 0, 0));
	result("down: to wall : objs", map_cmp(map2, mapcmp2));

	map_destroy(&map1);
	map_destroy(&map2);
	map_destroy(&mapcmp2);
	map_destroy(&mapcmp1);
	free(st);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_move_to_wall();

	printf("\n");
	return (0);
}
