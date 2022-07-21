/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 03:54:18 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"
#include <stdio.h>
#include <string.h>

void	result(const char *test, int result)
{
	if (result == TRUE)
		printf("- %s: ", "\033[0;32mPASS\033[;0m");
	if (result == FALSE)
		printf("- %s: ", "\033[0;31mFAIL\033[;0m");
	printf("%s\n", test);
}

void del_img(void *img)
{
	free(img);
}

void free_imgset(t_imgset **imgset)
{
	ft_lstclear(&(*imgset)->list, del_img);
	free(*imgset);
}

void	test_create(void)
{
	t_imgset	*imgset;

	imgset = imgset_create(ft_strdup("conteudo img"));
	result("create: valid pointer", imgset != NULL);
	result("create: image", imgset->img != NULL);
	result("create: images list", imgset->list != NULL);
	result("create: images list size", ft_lstsize(imgset->list) == 1);
	result("create: image content", strcmp(imgset->img, "conteudo img") == 0);
	free_imgset(&imgset);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_create();

	printf("\n");
	return (0);
}
