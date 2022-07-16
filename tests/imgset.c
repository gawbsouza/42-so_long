/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 13:41:09 by gasouza          ###   ########.fr       */
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

void	test_create(void)
{
	t_img		*img;
	t_imgset	*imgset;

	img = new_img("Conteudo IMG", 32, 42);
	imgset = imgset_create(img);
	result("create: valid pointer", imgset != NULL);
	result("create: image", imgset->img != NULL);
	result("create: images list", imgset->list != NULL);
	result("create: images list size", ft_lstsize(imgset->list) == 1);
	result("create: image content", strcmp(imgset->img->content, img->content) == 0);
	result("create: image width", imgset->img->width == img->width);
	result("create: image height", imgset->img->height == img->height);
	free_imgset(&imgset);
}

void	test_add_img(void)
{
	t_img		*img1, *img2, *img3;
	t_imgset	*imgset;

	img1 = new_img("IMG 1", 32, 32);
	img2 = new_img("IMG 2", 32, 32);
	img3 = new_img("IMG 3", 32, 32);
	imgset = imgset_create(img1);

	imgset_add_img(&imgset, img2);
	result("add_img: frames count #1", ft_lstsize(imgset->list) == 2);
	imgset_add_img(&imgset, img3);
	result("add_img: frames count #2", ft_lstsize(imgset->list) == 3);
	free_imgset(&imgset);
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

	test_create();
	test_add_img();
	test_spin();
	test_destroy();

	printf("\n");
	return (0);
}
