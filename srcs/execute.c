/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/01/20 20:21:22 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_manager(t_pipex *pipex, int	rfd, int wfd)
{
	if (pipex->count == 0)
	{
		dprintf(2, "first pross\n");
		dup2(rfd, STDIN);
		dup2(wfd, STDOUT);
	}
	else if(pipex->count == pipex->max_count - 1)
	{
		dprintf(2, "last pross\n");
		dup2(pipex->outfd, STDOUT);
		dup2(rfd, STDIN);
	}
	else 
	{
		dprintf(2, "in pross\n");
		close(pipex->infd);
		close(pipex->outfd);
		dup2(rfd, STDIN);
		dup2(wfd, STDOUT);
	}
}

void	ft_execute(t_pipex *pipex, int rfd, int wfd)
{
	int	count;
	fd_manager(pipex, rfd, wfd);
	count = pipex->count;
	dprintf(2, "count = %d | max = %d\n\n", count, pipex->max_count);
	execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
}

void	ft_start(t_pipex *pipex, int rfd)
{
	int pfd[2];
	int	pid;

	if(pipex->count <= pipex->max_count - 1)
	{
		pipe(pfd);
		pid = fork();
	}
	if (pipex->count >= pipex->max_count)
		return ;
	if (pid == 0)
		ft_execute(pipex, rfd , pfd[1]);
	else
	{
		wait(NULL);
		close(pfd[1]);
		pipex->count++;
		ft_start(pipex, pfd[0]);
	}
}