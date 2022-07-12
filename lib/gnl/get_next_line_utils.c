/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:30:10 by gasouza           #+#    #+#             */
/*   Updated: 2022/07/11 18:14:39 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_chr(const char *s, char c)
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

size_t	ft_str_len(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

size_t	ft_str_lcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_str_len(src);
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
		old_len = ft_str_len(*str);
		tmp = (char *) malloc((old_len + size + 1) * sizeof(char));
		if (tmp != NULL)
		{
			ft_str_lcpy(tmp, *str, old_len + 1);
			ft_str_lcpy(tmp + old_len, buffer, size + 1);
		}
	}
	free(*str);
	*str = tmp;
}
