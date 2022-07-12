/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:07:32 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/12 19:47:22 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include <stdio.h>
#include <string.h>

static void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

static int array_equals(char *const *a1, char *const *a2)
{
	if (array_size(a1) != array_size(a2))
		return (FALSE);
	while (a1 && a2 && *a1 && *a1)
	{
		if (strcmp(*a1, *a2) != 0)
			return (FALSE);
		a1++;
		a2++;
	}
	return (TRUE);
}

static void test_intern(void)
{
	char *array1[] = {"str1", "str2", NULL};
	char *array2[] = {"str2", "str1", NULL};
	char *array3[] = {"str3", NULL};
	char *array4[] = {"str1", "str2", NULL};
	char *array5[] = {NULL};

	result("array equals (INTERN)", array_equals(array1, array4) == TRUE);
	result("array diferent (INTERN)", array_equals(array1, array2) == FALSE);
	result("array diff sizes (INTERN)", array_equals(array2, array3) == FALSE);
	result("array null (INTERN)", array_equals(array5, array3) == FALSE);
}

static void test_empty(void)
{
	char *empty1[] = {NULL};
	char *empty2[] = {"  ", "  ", "  "};
	char *file1 = "./tests/maps/empty.ber";
	char *file2 = "./tests/maps/onlynewline.ber";
	char *file3 = "./tests/maps/spaces.ber";
	char *file4 = "./tests/maps/invalidfile";
	char **map1 = map_load_file(file1);
	char **map2 = map_load_file(file2);
	char **map3 = map_load_file(file3);
	char **map4 = map_load_file(file4);

	result("empty file", array_equals(map1, empty1) == TRUE);
	result("only new line", array_equals(map2, empty1) == TRUE);
	result("only spaces", array_equals(map3, empty2) == TRUE);
	result("invalid file name", array_equals(map4, empty1) == TRUE);
	free_array(map1);
	free_array(map2);
	free_array(map3);
	free_array(map4);
}

static void test_content(void)
{
	char *content1[] = {"111", "101", "111", NULL};
	char *content2[] = {"  ", "101", "1 1", NULL};
	char *file1 = "./tests/maps/content1.ber";
	char *file2 = "./tests/maps/content2.ber";
	char **map1 = map_load_file(file1);
	char **map2 = map_load_file(file2);

	result("content 1", array_equals(map1, content1) == TRUE);
	result("content 2", array_equals(map2, content2) == TRUE);
	free_array(map1);
	free_array(map2);
}

int	main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_intern();
	test_empty();
	test_content();

	printf("\n");
	return(0);
}
