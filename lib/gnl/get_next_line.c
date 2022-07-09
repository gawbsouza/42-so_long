/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:28:11 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/07 23:40:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	char		*n_pos;
	ssize_t		b_read;

	str = NULL;
	b_read = -1;
	while (!ft_strchr(str, '\n') && b_read != 0)
	{
		n_pos = ft_strchr(buffer, '\n');
		if (n_pos++)
		{
			add_str(&str, buffer, n_pos - buffer);
			ft_strlcpy(buffer, n_pos, ft_strlen(n_pos) + 1);
			continue ;
		}
		add_str(&str, buffer, ft_strlen(buffer));
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (NULL);
		buffer[b_read] = '\0';
	}
	return (str);
}
