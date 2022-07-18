/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:51 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/18 17:23:59 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include <stdio.h>
#include <stdlib.h>

void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

void test_destroy()
{
	char *map[] = {"1111", "1MC1", "10P1", "1EC1", "1111", NULL};
	t_map *gmap = map_create(map, TRUE);

	result("map created", gmap->lines == 5 && gmap->cols == 4 && gmap->objs);
	map_destroy(&gmap);
	result("map destroied", gmap == NULL);
}

int	main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_destroy();

	printf("\n");
	return (0);
}
