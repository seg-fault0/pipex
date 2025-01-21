/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/01/21 01:14:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_manager(t_pipex *pipex, int	rfd, int wfd)
{
	dup2(rfd, STDIN);
	if (pipex->count == pipex->max_count - 1)
	{
		dup2(pipex->outfd, STDOUT);
		close(wfd);
	}
	else
		dup2(wfd, STDOUT);
}

void	ft_execute(t_pipex *pipex, int rfd, int wfd)
{
	int	count;
	fd_manager(pipex, rfd, wfd);
	count = pipex->count;
	execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
}

void	ft_start(t_pipex *pipex, int rfd)
{
	int pfd[2];
	int	pid;

	if (pipex->count == pipex->max_count)
		return ;
	pipe(pfd);
	pid = fork();
	if (pid == 0)
	{
		ft_execute(pipex, rfd , pfd[1]);
		if (pipex->count != 0)
			close (rfd);
		close_pipe(pfd);
	}
	else
	{
		wait(NULL);
		close(pfd[1]);
		pipex->count++;
		ft_start(pipex, pfd[0]);
	}
}