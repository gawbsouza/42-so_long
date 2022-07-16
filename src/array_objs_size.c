/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_objs_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:53:03 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/16 18:53:32 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	array_objs_size(t_obj **array)
{
	size_t	size;

	size = 0;
	while (array && *array)
	{
		size++;
		array++;
	}
	return (size);
}
