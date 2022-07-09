/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:30:10 by gasouza           #+#    #+#             */
/*   Updated: 2022/05/07 21:45:56 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, char c)
{
	if (s != NULL)
	{
		while (*s && *s != c)
			s++;
		if (*s == c)
			return ((char *) s);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size--)
	{		
		while (size-- && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}

void	add_str(char **str, const char *buffer, size_t size)
{
	char	*tmp;
	size_t	old_len;

	tmp = NULL;
	if (buffer[0])
	{
		old_len = ft_strlen(*str);
		tmp = (char *) malloc((old_len + size + 1) * sizeof(char));
		if (tmp != NULL)
		{
			ft_strlcpy(tmp, *str, old_len + 1);
			ft_strlcpy(tmp + old_len, buffer, size + 1);
		}
	}
	free(*str);
	*str = tmp;
}
