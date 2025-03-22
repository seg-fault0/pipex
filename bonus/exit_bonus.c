/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/22 23:44:33 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

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

void	free_all(t_pipex *pipex)
{
	ft_close(pipex->infd);
	ft_close(pipex->outfd);
	free_cmd(pipex->cmd);
	free(pipex->children_pid);
}

void	ft_free2darr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_exit(t_pipex *pipex)
{
	int	code;

	code = WEXITSTATUS(pipex->exit_code);
	free_all(pipex);
	exit(code);
}

void	close_pipe(int *fd)
{
	ft_close (fd[0]);
	ft_close (fd[1]);
}
