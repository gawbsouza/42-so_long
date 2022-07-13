/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:17:00 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/13 10:18:26 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include <stddef.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define BONUS 0

# define WALL_CHAR '1'
# define EMPTY_CHAR '0'
# define COLLECT_CHAR 'C'
# define EXIT_CHAR 'E'
# define PLAYER_CHAR 'P'
# define MOSTER_CHAR 'M'

char	**map_load_file(const char *file);
int		map_check(char *const *map, int bonus);
size_t	array_size(char *const *array);
void	free_array(char **array);

#endif
