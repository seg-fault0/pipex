/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/16 23:14:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	close(pipex->infd);
	close(pipex->outfd);
	free_cmd(pipex->cmd);
	free(pipex);
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
	close (fd[0]);
	close (fd[1]);
}
