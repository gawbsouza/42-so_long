/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:17:00 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/21 13:40:57 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "so_types.h"
# include <stddef.h>
# include <fcntl.h>
# include <X11/keysym.h>

# define TRUE 1
# define FALSE 0
# define BONUS 0
# define WALL_CHAR '1'
# define EMPTY_CHAR '0'
# define COLLECT_CHAR 'C'
# define EXIT_CHAR 'E'
# define PLAYER_CHAR 'P'
# define MONSTER_CHAR 'M'
# define TO_LEFT 'l' 
# define TO_RIGHT 'r'
# define TO_UP 'u'
# define TO_DOWN 'd'
# define SPRITE_WIDTH 32
# define SPRITE_HEIGHT 32

char		**map_load_file(const char *file);
int			map_valid_file_ext(const char *file);
int			map_check(char *const *map, int bonus);
t_map		*map_create(char *const *map, int bonus);
void		map_destroy(t_map **map);
size_t		array_size(char *const *array);
size_t		array_objs_size(t_obj **array);
void		free_array(char **array);
t_stat		*stat_create(int moves, int collects, int dead, int end);
t_imgset	*imgset_create(char *img);
void		imgset_add_img(t_imgset **imgset, char *img);
void		imgset_spin(t_imgset **imgset);
void		imgset_destroy(t_imgset **imgset);
t_pos		*player_get_pos(t_map *map);
void		player_move(char dir, t_map *map, t_stat *st);
t_assets	*assets_create(t_gui *gui, int base_w, int base_h);
void		assets_destroy(t_gui *gui, t_assets **assets);
t_gui		*gui_create(int width, int height, char *title);
void		gui_destroy(t_gui **gui);
void		window_draw(t_gui *gui, t_assets *assets, t_map *map);
t_game		*game_create(char *const *map, int base_w, int base_h, int bonus);
void		game_destroy(t_game **game);
t_game		*game_init(const char *file);
int			game_loop(t_game *game);

#endif
