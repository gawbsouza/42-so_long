/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:37:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/19 18:26:08 by gasouza          ###   ########.fr       */
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

void	test_move_dead_end()
{
	t_stat	*stdead = new_stat(0, 0, 1, 0);
	t_stat	*stend = new_stat(0, 0, 0, 1);
	t_stat	*stdeadend = new_stat(0, 0, 1, 1);
	char *mapstr[] = {"11111", "1PCE1", "11111", NULL};
	t_map *map = map_create(mapstr, FALSE); 
	t_map *mapcmp = map_create(mapstr, FALSE); 

	player_move(TO_LEFT, map, stdead);
	result("status dead", map_cmp(map, mapcmp));
	player_move(TO_LEFT, map, stend);
	result("status end", map_cmp(map, mapcmp));
	player_move(TO_LEFT, map, stdeadend);
	result("status dead and end", map_cmp(map, mapcmp));

	map_destroy(&map);
	map_destroy(&mapcmp);
	free(stdead);
	free(stend);
	free(stdeadend);
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

void	test_move_to_empty()
{
	t_stat *st = new_stat(0, 0, 0, 0);
	char *mapstr[] = {"11111", "100E1", "10PC1", "11111", NULL};
	t_map *map = map_create(mapstr, FALSE);
	t_map *mapcmp = map_create(mapstr, FALSE);

	// 11111, 100E1, 1P0C1, 11111
	mapcmp->objs[2][1].type = PLAYER;
	mapcmp->objs[2][2].type = EMPTY;
	player_move(TO_LEFT, map, st);
	result("left: to empty : status", stat_cmp(st, 0, 1, 0, 0));
	result("left: to empty : objs", map_cmp(map, mapcmp));
	
	// 11111, 1P0E1, 100C1, 11111
	mapcmp->objs[1][1].type = PLAYER;
	mapcmp->objs[2][1].type = EMPTY;
	player_move(TO_UP, map, st);
	result("up: to empty : status", stat_cmp(st, 0, 2, 0, 0));
	result("up: to empty : objs", map_cmp(map, mapcmp));

	// 11111, 10PE1, 100C1, 11111
	mapcmp->objs[1][2].type = PLAYER;
	mapcmp->objs[1][1].type = EMPTY;
	player_move(TO_RIGHT, map, st);
	result("right: to empty : status", stat_cmp(st, 0, 3, 0, 0));
	result("right: to empty : objs", map_cmp(map, mapcmp));
	
	// 11111, 100E1, 10PC1, 11111
	mapcmp->objs[2][2].type = PLAYER;
	mapcmp->objs[1][2].type = EMPTY;
	player_move(TO_DOWN, map, st);
	result("down: to empty : status", stat_cmp(st, 0, 4, 0, 0));
	result("down: to empty : objs", map_cmp(map, mapcmp));

	map_destroy(&map);
	map_destroy(&mapcmp);
	free(st);
}

void	test_move_to_collect()
{
	t_stat *st = new_stat(0, 0, 0, 0);
	char *mapstr[] = {"11111", "1CCE1", "1CPC1", "11111", NULL};
	t_map *map = map_create(mapstr, FALSE);
	t_map *mapcmp = map_create(mapstr, FALSE);

	// 11111, 1CCE1, 1P0C1, 11111
	mapcmp->objs[2][1].type = PLAYER;
	mapcmp->objs[2][2].type = EMPTY;
	player_move(TO_LEFT, map, st);
	result("left: to collect : status", stat_cmp(st, 1, 1, 0, 0));
	result("left: to collect : objs", map_cmp(map, mapcmp));
	
	// 11111, 1PCE1, 100C1, 11111
	mapcmp->objs[1][1].type = PLAYER;
	mapcmp->objs[2][1].type = EMPTY;
	player_move(TO_UP, map, st);
	result("up: to collect : status", stat_cmp(st, 2, 2, 0, 0));
	result("up: to collect : objs", map_cmp(map, mapcmp));

	// 11111, 10PE1, 100C1, 11111
	mapcmp->objs[1][2].type = PLAYER;
	mapcmp->objs[1][1].type = EMPTY;
	player_move(TO_RIGHT, map, st);
	result("right: to collect : status", stat_cmp(st, 3, 3, 0, 0));
	result("right: to collect : objs", map_cmp(map, mapcmp));
	
	// 11111, 100E1, 10PC1, 11111
	map->objs[2][2].type = COLLECT;
	mapcmp->objs[2][2].type = PLAYER;
	mapcmp->objs[1][2].type = EMPTY;
	player_move(TO_DOWN, map, st);
	result("down: to collect : status", stat_cmp(st, 4, 4, 0, 0));
	result("down: to collect : objs", map_cmp(map, mapcmp));

	map_destroy(&map);
	map_destroy(&mapcmp);
	free(st);
}

void	test_move_to_exit()
{
	t_stat *st = new_stat(0, 0, 0, 0);
	char *mapstr[] = {"11111", "1EPC1", "11111", NULL};
	t_map *map = map_create(mapstr, FALSE);
	t_map *mapcmp = map_create(mapstr, FALSE);

	player_move(TO_LEFT, map, st);
	result("exit: without collect : status", stat_cmp(st, 0, 0, 0, 0));
	result("exit: without collect : objs", map_cmp(map, mapcmp));

	mapcmp->objs[1][2].type = EMPTY;
	st->collects = 1;
	player_move(TO_LEFT, map, st);
	result("exit: with collect : status", stat_cmp(st, 1, 1, 0, 1));
	result("exit: with collect : objs", map_cmp(map, mapcmp));

	map_destroy(&map);
	map_destroy(&mapcmp);
	free(st);
}

void	test_move_to_monster()
{
	t_stat *st = new_stat(0, 0, 0, 0);
	char *mapstr[] = {"111111", "1MPEC1", "111111", NULL};
	t_map *map = map_create(mapstr, TRUE);
	t_map *mapcmp = map_create(mapstr, TRUE);

	player_move(TO_LEFT, map, st);
	mapcmp->objs[1][2].type = EMPTY;
	result("monster: status", stat_cmp(st, 0, 1, 1, 1));
	result("monster: objs", map_cmp(map, mapcmp));


	map_destroy(&map);
	map_destroy(&mapcmp);
	free(st);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_move_dead_end();
	test_move_to_wall();
	test_move_to_empty();
	test_move_to_collect();
	test_move_to_exit();
	test_move_to_monster();

	printf("\n");
	return (0);
}
