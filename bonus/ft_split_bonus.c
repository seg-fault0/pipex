/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:32:44 by wimam             #+#    #+#             */
/*   Updated: 2025/02/16 04:42:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmpdst;
	char	*tmpsrc;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst == src)
		return (dst);
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		i++;
	}
	return (dst);
}

static int	ft_row(char const *s, char c)
{
	int		ret;

	ret = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			ret++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

static char	*ft_fill(char const *s, char c)
{
	int		len;
	char	*buffer;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s, len);
	buffer[len] = '\0';
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		row;
	int		i;

	if (!s)
		return (NULL);
	row = ft_row(s, c);
	buffer = malloc((row + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		buffer[i++] = ft_fill(s, c);
		while (*s && *s != c)
			s++;
	}
	buffer[row] = NULL;
	return (buffer);
}
