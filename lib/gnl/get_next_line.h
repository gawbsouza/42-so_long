/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:05 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/11 18:14:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 4096

char	*get_next_line(int fd);
char	*ft_str_chr(const char *s, char c);
size_t	ft_str_len(const char *s);
size_t	ft_str_lcpy(char *dst, const char *src, size_t size);
void	add_str(char **str, const char *buffer, size_t size);

#endif
