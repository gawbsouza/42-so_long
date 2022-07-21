/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:03:33 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 02:05:42 by gasouza          ###   ########.fr       */
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

static void test_destroy(void)
{
	char *mapstr[] = {"11111", "1PCE1", "11111", NULL};
	t_game *game = game_create(mapstr, 32, 32, FALSE);

	result("create", game != NULL);
	game_destroy(&game);
	result("destroy", game == NULL);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_destroy();

	printf("\n");
	return (0);
}
