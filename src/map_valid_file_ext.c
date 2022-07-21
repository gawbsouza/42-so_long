/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_file_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:03:18 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 12:27:24 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_valid_file_ext(const char *file)
{
	size_t	file_len;
	size_t	ext_len;
	char	*ext;

	if (!file)
		return (FALSE);
	ext = ".ber";
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (file_len - ext_len < 1)
		return (FALSE);
	if (!ft_strnstr(file + (file_len - ext_len), ext, ext_len))
		return (FALSE);
	return (TRUE);
}
