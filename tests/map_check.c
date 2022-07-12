/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:33:52 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/12 19:46:51 by gasouza          ###   ########.fr       */
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

void	test_blanks(void)
{
	char *onlyspace[] = {"  ", "  ", "  ", NULL};
	char *randspace[] = {"1111", "10 1", "1111", NULL};
	char *fewlines[] = {"1111", "1111", NULL};
	char *emptyline[] = {"1111", "1001", "", "1111", NULL};
	
	result("nulll pointer", map_check(NULL) == FALSE);
	result("only spaces", map_check(onlyspace) == FALSE);
	result("random spaces", map_check(randspace) == FALSE);
	result("few lines", map_check(fewlines) == FALSE);
	result("empty line", map_check(emptyline) == FALSE);
}

void	test_components(void)
{
	char *mapok[] = {"11111", "1EPC1", "11111", NULL};
	char *noexit[] = {"11111", "10PC1", "11111", NULL};
	char *noplayer[] = {"11111", "1E0C1", "11111", NULL};
	char *nocollect[] = {"11111", "1EP01", "11111", NULL};
	char *nocomps[] = {"11111", "10001", "11111", NULL};
	char *invcompmiddle[] = {"111111", "1SEPC1", "111111", NULL};
	char *invcomptop[] = {"114111", "10EPC1", "111111", NULL};
	char *invcompbottom[] = {"111111", "10EPC1", "11W111", NULL};
	
	result("map correct", map_check(mapok) == TRUE);
	result("no exit", map_check(noexit) == FALSE);
	result("no player", map_check(noplayer) == FALSE);
	result("no collect", map_check(nocollect) == FALSE);
	result("no components", map_check(nocomps) == FALSE);
	result("invalid component middle", map_check(invcompmiddle) == FALSE);
	result("invalid component top", map_check(invcomptop) == FALSE);
	result("invalid component bottom", map_check(invcompbottom) == FALSE);
}

void	test_form(void)
{
	char *invtopwall[] = {"011111", "1PCE01", "111111", NULL};
	char *invbotwall[] = {"111111", "1PCE01", "110111", NULL};
	char *invleftwall[] = {"111111", "0PCE01", "111111", NULL};
	char *invrightwall[] = {"111111", "1PCE00", "111111", NULL};
	char *squared[] = {"1111", "10P1", "1EC1", "1111", NULL};
	char *randlinesize[] = {"1111111", "1PCE01", "111", NULL};

	result("invalid top wall", map_check(invtopwall) == FALSE);
	result("invalid bottom wall", map_check(invbotwall) == FALSE);
	result("invalid left wall", map_check(invleftwall) == FALSE);
	result("invalid right wall", map_check(invrightwall) == FALSE);
	result("squared format", map_check(squared) == FALSE);
	result("random lines size", map_check(randlinesize) == FALSE);
}
	
int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_blanks();
	test_components();
	test_form();

	printf("\n");
	return (0);
}
