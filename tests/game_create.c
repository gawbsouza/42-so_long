/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:26:01 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 01:57:14 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include <stdio.h>

static void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

static void game_destroy(t_game **game)
{
	if (!game || !*game)
		return ;
	free((*game)->stat);
	map_destroy(&(*game)->map);
	assets_destroy((*game)->gui, &(*game)->assets);
	gui_destroy(&(*game)->gui);
	free(*game);
	*game = NULL;
}

static void test_create(void)
{
	char *mapstr[] = {"11111", "1PCE1", "11111", NULL};
	t_game *game = game_create(mapstr, 32, 32, FALSE);

	result("big size", game_create(mapstr, 3000, 3000, FALSE) == FALSE);
	result("invalid width", game_create(mapstr, 0, 32, FALSE) == FALSE);
	result("invalid height", game_create(mapstr, 32, 0, FALSE) == FALSE);
	result("create",  game != NULL);
	result("game stat", game->stat != NULL);
	result("game map", game->map != NULL);
	result("game gui", game->gui != NULL);
	result("game assets", game->assets != NULL);
	game_destroy(&game);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_create();

	printf("\n");
	return (0);
}
