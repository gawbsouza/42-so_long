/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:27:13 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 04:00:06 by gasouza          ###   ########.fr       */
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


static void	test_assets(void)
{
	t_gui *gui;
	t_assets *assets;

	gui = (t_gui *) malloc(sizeof(t_gui));
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, 300, 300, "gasouza");

	assets = assets_create(gui, 32, 32);
	result("invalid gui", assets_create(NULL, 32, 32) == NULL);
	result("invalid width", assets_create(gui, 0, 32) == NULL);
	result("invalid height", assets_create(gui, 32, 0) == NULL);
	result("created", assets != NULL);
	result("valid empty asset", assets->empty != NULL);
	result("valid wall asset", assets->wall != NULL);
	result("valid player asset", assets->player != NULL);
	result("valid monster asset", assets->monster != NULL);
	result("valid colletc asset", assets->collect != NULL);
	result("valid exit asset", assets->exit != NULL);
	assets_destroy(gui, &assets);
	gui_destroy(&gui);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_assets();

	printf("\n");
	return (0);
}
