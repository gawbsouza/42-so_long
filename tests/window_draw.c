/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:59:21 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 22:52:10 by gasouza          ###   ########.fr       */
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

void	test_draw(void)
{
	char *mapstr[] = {"111111", "1PMEC1", "111111", NULL};
	t_map *map = map_create(mapstr, TRUE);
	int base_w = 32 * map->cols;
	int	base_h = 32 * map->lines;
	t_gui *gui = gui_create(base_w, base_h, "gasouza");
	t_assets *assets = assets_create(gui, base_w, base_h);

	result("draw", window_draw(gui, assets, map));
	assets_destroy(gui, &assets);
	map_destroy(&map);
	gui_destroy(&gui);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_draw();

	printf("\n");
	return (0);
}
