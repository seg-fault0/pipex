/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/03/06 13:29:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*buffer;
	int		i;

	buffer = malloc(ft_strlen(s + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while(s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	add_path(t_pipex *pipex)
{
	char *tmp;

	tmp = pipex->cmd1[0];
	if (access(tmp, X_OK))
	{
		pipex->cmd1[0] = ft_strjoin(BIN_PATH, tmp);
		free(tmp);
	}
	tmp = pipex->cmd2[0];
	if (access(tmp, X_OK))
	{
		pipex->cmd2[0] = ft_strjoin(BIN_PATH, tmp);
		free(tmp);
	}
}

t_pipex	*pipex_init(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (error_msg(5), NULL);
	pipex->infd = open(argv[0], O_RDONLY);
	if (pipex->infd < 0 && access(argv[0], R_OK))
		return (free(pipex), error_msg(10), exit(1), NULL);
	if (pipex->infd < 0)
		return (free(pipex), error_msg(6), exit(1), NULL);
	pipex->outfd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->outfd < 0)
		return (close(pipex->infd), free(pipex), error_msg(6), NULL);
	pipex->cmd1 = ft_split(argv[1], ' ');
	pipex->cmd2 = ft_split(argv[2], ' ');
	add_path(pipex);
	return (pipex);
}
