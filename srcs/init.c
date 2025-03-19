/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/03/19 22:14:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	**ft_get_paths(char **env)
{
	char	*tmp;
	char	**paths;
	int		i;

	i = -1;
	while (env[++i])
		if (ft_memcmp("PATH", env[i], 4) == 0)
			tmp = env[i] + 5;
	paths = ft_split(tmp, ':');
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		if (tmp[ft_strlen(tmp) - 1] != '/')
		{
			paths[i] = ft_strjoin(tmp, "/");
			free(tmp);
		}
		i++;
	}
	return (paths);
}

void	ft_add_path(t_pipex *pipex, char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**paths;

	paths = ft_get_paths(env);
	i = -1;
	while (pipex->cmd[++i])
	{
		j = -1;
		while (paths[++j])
		{
			tmp = ft_strjoin(paths[j], pipex->cmd[i][0]);
			if (!access(tmp, X_OK))
			{
				free(pipex->cmd[i][0]);
				pipex->cmd[i][0] = tmp;
				break ;
			}
			free(tmp);
		}
	}
	ft_free2darr(paths);
}

char	***get_cmd(int argc, char **argv)
{
	char	***cmd;
	int		i;

	cmd = malloc ((argc - 2) * sizeof(char **) + 1);
	if (!cmd)
		return (NULL);
	i = 0;
	while (i < argc - 2)
	{
		cmd[i] = ft_split(argv[i + 1], ' ');
		if (!cmd[i])
			return (error_msg(5), cmd);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

t_pipex	*pipex_init(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (error_msg(5), NULL);
	pipex->children_pid = malloc((argc - 2) * sizeof(int));
	if (!pipex->children_pid)
		return (free(pipex), error_msg(5), NULL);
	pipex->infd = open(argv[0], O_RDONLY);
	if (pipex->infd < 0 && access(argv[0], F_OK))
		return (free(pipex), error_msg(6), exit(1), NULL);
	if (pipex->infd < 0)
		return (free(pipex), error_msg(10), exit(1), NULL);
	pipex->outfd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->outfd < 0)
		return (close(pipex->infd), free(pipex), error_msg(6), NULL);
	pipex->cmd = get_cmd(argc, argv);
	if (!pipex->cmd)
		return (ft_exit(pipex), NULL);
	ft_add_path(pipex, env);
	pipex->count = 0;
	pipex->max_count = argc - 2;
	pipex->exit_code = 0;
	return (pipex);
}
