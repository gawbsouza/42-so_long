/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_spin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:46:38 by gasouza          ###   ########.fr       */
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

void	test_spin(void)
{
	t_img		*img1, *img2;
	t_imgset	*imgset;

	img1 = new_img("IMG 1", 32, 32);
	img2 = new_img("IMG 2", 32, 32);
	imgset = imgset_create(img1);

	imgset_spin(&imgset);
	result("spin: one image", imgset->img == img1);
	imgset_add_img(&imgset, img2);
	imgset_spin(&imgset);
	result("spin: two images : 1 -> 2", imgset->img == img2);
	imgset_spin(&imgset);
	result("spin: two images : 2 -> 1", imgset->img == img1);
	free_imgset(&imgset);
}

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_spin();

	printf("\n");
	return (0);
}
