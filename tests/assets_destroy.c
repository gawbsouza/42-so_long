/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:15:26 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 04:00:43 by gasouza          ###   ########.fr       */
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

static void	test_destroy(void)
{
	t_gui *gui;
	t_assets *assets;

	gui = (t_gui *) malloc(sizeof(t_gui));
	gui->mlx = mlx_init();
	gui->win = mlx_new_window(gui->mlx, 300, 300, "gasouza");

	assets = assets_create(gui, 32, 32);
	result("created", assets != NULL);
	assets_destroy(gui, &assets);
	result("destroied", assets == NULL);
	gui_destroy(&gui);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_destroy();

	printf("\n");
	return (0);
}
