/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/02/16 05:12:42 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_add_path(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->cmd[i])
	{
		tmp = pipex->cmd[i][0];
		pipex->cmd[i][0] = ft_strjoin(BIN_PATH, pipex->cmd[i][0]);
		free(tmp);
		i++;
	}
}

int	are_cmd_exe(char ***cmd)
{
	int		i;
	char	*tmp_cmd;

	i = 0;
	while (cmd[i])
	{
		tmp_cmd = ft_strjoin(BIN_PATH, cmd[i][0]);
		if (access(tmp_cmd, X_OK) != 0)
			return (free(tmp_cmd), error_msg(4), 1);
		free(tmp_cmd);
		i++;
	}
	return (0);
}

char	***get_cmd(int argc, char *argv[])
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

t_pipex	*pipex_init(int argc, char *argv[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(pipex));
	if (!pipex)
		return (error_msg(5), NULL);
	pipex->infd = open(argv[0], O_RDONLY);
	if (pipex->infd < 0)
		return (free(pipex), error_msg(6), NULL);
	pipex->outfd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->outfd < 0)
		return (close(pipex->infd), free(pipex), error_msg(6), NULL);
	pipex->cmd = get_cmd(argc, argv);
	if (!pipex->cmd)
		return (ft_exit(pipex), NULL);
	if (are_cmd_exe(pipex->cmd))
		ft_exit(pipex);
	ft_add_path(pipex);
	pipex->count = 0;
	pipex->max_count = argc - 2;
	return (pipex);
}
