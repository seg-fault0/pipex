/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/23 00:08:46 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		while (cmd[i][j])
			free(cmd[i][j++]);
		free(cmd[i++]);
	}
	free(cmd);
}

void	ft_free2darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	close_pipe(int *fd)
{
	ft_close (fd[0]);
	ft_close (fd[1]);
}

void	free_all(t_pipex *pipex)
{
	ft_close(pipex->infd);
	ft_close(pipex->outfd);
	free_cmd(pipex->cmd);
	free(pipex->children_pid);
}

void	ft_exit(t_pipex *pipex)
{
	int	code;

	code = WEXITSTATUS(pipex->exit_code);
	free_all(pipex);
	exit(code);
}
