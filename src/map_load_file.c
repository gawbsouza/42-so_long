/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:58:56 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 12:39:24 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	*fd_to_str(int fd)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	close(fd);
	return (str);
}

char	**map_load_file(const char *file)
{
	int		fd;
	char	**map;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd <= -1)
	{
		ft_printf("Invalid Map: file not found or invalid.\n");
		return (NULL);
	}
	buffer = fd_to_str(fd);
	map = ft_split(buffer, '\n');
	free(buffer);
	return (map);
}
