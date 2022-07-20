/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:53:19 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 20:56:40 by gasouza          ###   ########.fr       */
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

void	test_create()
{

	t_gui *gui;

	gui = gui_create(300, 300, "gasouza");
	result("invalid width", gui_create(0, 300, "gasouza") == NULL);
	result("invalid height", gui_create(300, 0, "gasouza") == NULL);
	result("invalid title", gui_create(300, 300, NULL) == NULL);
	result("create", gui != NULL);
	gui_destroy(&gui);
	
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_create();

	printf("\n");
	return (0);
}
