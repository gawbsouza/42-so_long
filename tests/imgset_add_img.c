/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_add_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 03:56:00 by gasouza          ###   ########.fr       */
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

void	test_add_img(void)
{
	char		*img1, *img2, *img3;
	t_imgset	*imgset;

	img1 = ft_strdup("img 1");
	img2 = ft_strdup("img 2");
	img3 = ft_strdup("img 3");
	imgset = imgset_create(img1);

	imgset_add_img(&imgset, img2);
	result("add_img: frames count #1", ft_lstsize(imgset->list) == 2);
	imgset_add_img(&imgset, img3);
	result("add_img: frames count #2", ft_lstsize(imgset->list) == 3);
	free_imgset(&imgset);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_add_img();

	printf("\n");
	return (0);
}
