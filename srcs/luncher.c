/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/02/18 03:25:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_manager(t_pipex *pipex, int rfd, int wfd)
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
	int	failed;

	fd_manager(pipex, rfd, wfd);
	count = pipex->count;
	failed = execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
	if (failed == -1)
		return (error_msg(7), (void)0);
}

void	ft_start(t_pipex *pipex, int rfd)
{
	int	pfd[2];
	int	pid;

	if (pipex->count == pipex->max_count)
		return ;
	pid = pipe(pfd);
	if (pid == -1)
		return (close(rfd), error_msg(8), ft_exit(pipex));
	pid = fork();
	if (pid == -1)
		return (close (rfd), close_pipe(pfd), error_msg(9), ft_exit(pipex));
	if (pid == 0)
	{
		ft_execute(pipex, rfd, pfd[1]);
		close (rfd);
		close_pipe(pfd);
	}
	else
	{
		wait(NULL);
		close(pfd[1]);
		close(rfd);
		pipex->count++;
		ft_start(pipex, pfd[0]);
	}
}
