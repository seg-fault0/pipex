/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:02:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/16 04:30:44 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;
	size_t				i;

	buffer1 = (const unsigned char *) s1;
	buffer2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (buffer1[i] != buffer2[i])
			return (buffer1[i] - buffer2[i]);
		i++;
	}
	return (0);
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
