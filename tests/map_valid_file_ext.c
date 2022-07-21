/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_file_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:14:29 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 12:19:33 by gasouza          ###   ########.fr       */
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

static void test_file(void)
{
	result("null", map_valid_file_ext(NULL) == FALSE);
	result("invalid ext", map_valid_file_ext("01.bar") == FALSE);
	result("only ext", map_valid_file_ext(".ber") == FALSE);
	result("valid name #1", map_valid_file_ext("1.ber") == TRUE);
	result("valid name #2", map_valid_file_ext("01.ber") == TRUE);
	result("valid name #3", map_valid_file_ext("maps/01.ber") == TRUE);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_file();

	printf("\n");
	return (0);
}
