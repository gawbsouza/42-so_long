/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:47:39 by gasouza          ###   ########.fr       */
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

t_img *new_img(char *content, int w, int h)
{
	t_img		*img;

	img = (t_img *) malloc(sizeof(t_img));
	if (img)
	{
		img->content = content;
		img->width = w;
		img->height = h;
	}
	return (img);
}

void	test_destroy(void)
{
	t_img *img1 = new_img("img", 32, 32);
	t_img *img2 = new_img("img", 32, 32);
	t_imgset *imgset = imgset_create(img1);

	imgset_destroy(&imgset);
	result("destroy: one image", imgset == NULL);
	imgset = imgset_create(img1);
	imgset_add_img(&imgset, img2);
	imgset_destroy(&imgset);
	result("destroy: two images", imgset == NULL);
	free(img1);
	free(img2);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_destroy();

	printf("\n");
	return (0);
}
