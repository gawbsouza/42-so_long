/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:27:13 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 16:43:36 by gasouza          ###   ########.fr       */
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

void assets_destroy(t_assets **assets, t_gui *gui)
{
	if (!assets || !*assets)
		return ;
	mlx_destroy_image(gui->mlx, (*assets)->empty->img);
	mlx_destroy_image(gui->mlx, (*assets)->wall->img);
	mlx_destroy_image(gui->mlx, (*assets)->player->img);
	mlx_destroy_image(gui->mlx, (*assets)->collect->img);
	mlx_destroy_image(gui->mlx, (*assets)->exit->img);
	mlx_destroy_image(gui->mlx, (*assets)->monster->img);
	imgset_destroy(&(*assets)->empty);
	imgset_destroy(&(*assets)->wall);
	imgset_destroy(&(*assets)->player);
	imgset_destroy(&(*assets)->collect);
	imgset_destroy(&(*assets)->monster);
	imgset_destroy(&(*assets)->exit);
	free(*assets);
	*assets = NULL;
}

void gui_destroy(t_gui **gui)
{
	if (!gui || !*gui)
		return ;
	mlx_destroy_window((*gui)->mlx, (*gui)->win);
	mlx_destroy_display((*gui)->mlx);
	free((*gui)->mlx);
	free(*gui);
	*gui = NULL;
}

void	test_assets(void)
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
	assets_destroy(&assets, gui);
	gui_destroy(&gui);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_assets();

	printf("\n");
	return (0);
}
