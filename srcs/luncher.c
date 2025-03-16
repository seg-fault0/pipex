/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/03/16 01:54:51 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_manager(t_pipex *pipex, int rfd, int wfd)
{
	dup2(rfd, STDIN);
	if (pipex->count == pipex->max_count - 1)
		dup2(pipex->outfd, STDOUT);
	else
		dup2(wfd, STDOUT);
}

void	ft_chiled(t_pipex *pipex, int rfd, int *pfd)
{
	int	count;
	int	failed;

	fd_manager(pipex, rfd, pfd[1]);
	count = pipex->count;
	close (rfd);
	close_pipe(pfd);
	failed = execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
	if (failed == -1)
	{
		error_msg(7);
		free_all(pipex);
		exit(127);
	}
}

void	ft_start(t_pipex *pipex, int rfd)
{
	int	pfd[2];
	int	pid;

	if (pipex->count == pipex->max_count)
		return ;
	if (pipe(pfd))
		return (close(rfd), error_msg(8), ft_exit(pipex));
	pid = fork();
	if (pid == -1)
		return (close (rfd), close_pipe(pfd), error_msg(9), ft_exit(pipex));
	if (pid == 0)
		ft_chiled(pipex, rfd, pfd);
	else
	{
		close_pipe((int []){pfd[1], rfd});
		pipex->count++;
		ft_start(pipex, pfd[0]);
		close(pfd[0]);
		wait(&pipex->exit_code);
	}
}
