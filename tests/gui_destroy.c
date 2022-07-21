/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:03:10 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/20 21:09:56 by gasouza          ###   ########.fr       */
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

void	test_destroy(void)
{
	t_gui *gui;
	gui = gui_create(300, 300, "gasouza");

	result("create", gui != NULL);
	gui_destroy(&gui);
	result("destroy", gui == NULL);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_destroy();

	printf("\n");
	return (0);
}
