/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:32:44 by wimam             #+#    #+#             */
/*   Updated: 2025/03/05 16:17:42 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	get_len(const char *s, char c)
{
	int	len;

	len = 0;
	if (*s != '\'')
		while (s[len] && s[len] != c)
			len++;
	else
	{
		s++;
		while (s[len] && s[len] != '\'')
			len++;
	}
	return (len);
}

static char	*ft_fill(char const **s, char c)
{
	int		len;
	char	*buffer;

	len = get_len(*s, c);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	if (s[0][0] != '\'')
		ft_memcpy(buffer, s[0], len);
	else
		ft_memcpy(buffer, &s[0][1], len);
	buffer[len] = '\0';
	if (s[0][0] == '\'')
		*s += 2;
	*s += len;
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
	while (i < row && *s)
	{
		while (*s && *s == c)
			s++;
		buffer[i++] = ft_fill(&s, c);
	}
	buffer[row] = NULL;
	return (buffer);
}
