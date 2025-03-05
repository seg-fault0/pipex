/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:02:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/05 15:03:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*buffer;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (*s1)
	{
		buffer[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		buffer[i] = *s2;
		i++;
		s2++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	close_pipe(int *fd)
{
	close (fd[0]);
	close (fd[1]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\n')
		return (1);
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

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
