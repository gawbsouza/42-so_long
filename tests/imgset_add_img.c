/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgset_add_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 08:56:17 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:45:56 by gasouza          ###   ########.fr       */
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

int main(void)
{
	printf("\n%s\n", __FILE_NAME__);

	test_add_img();

	printf("\n");
	return (0);
}
