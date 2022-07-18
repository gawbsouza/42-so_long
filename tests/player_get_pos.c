/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:20:37 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/18 17:24:51 by gasouza          ###   ########.fr       */
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

void	test_get_pos()
{
	char	*mapnoplayer[] = {"11111", "10001", "11111", NULL};
	char	*mapplayerx2y1[] = {"11111", "1CPE1", "11111", NULL};
	char	*mapplayerx3y2[] = {"11111", "1CME1", "100P1" ,"11111", NULL};
	t_map	*map1 = map_create(mapnoplayer, FALSE);
	t_map	*map2 = map_create(mapplayerx2y1, FALSE);
	t_map	*mapbonus = map_create(mapplayerx3y2, TRUE);
	t_pos	*p1 = player_get_pos(map1);
	t_pos	*p2 = player_get_pos(map2);
	t_pos	*b = player_get_pos(mapbonus);

	result("no player", p1 == NULL);
	result("player x: 2, y: 1", p2->x == 2 && p2->y == 1);
	result("player x: 3, y: 2 - Bonus", b->x == 3 && b->y == 2);
	// criar map_destoy antes de commitar o player_get_pos
	map_destroy(&map1);
	map_destroy(&map2);
	map_destroy(&mapbonus);
	free(p1);
	free(p2);
	free(b);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_get_pos();

	printf("\n");
	return (0);
}
