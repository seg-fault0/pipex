/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/03/06 14:22:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_chiled(t_pipex *pipex, int *pfd)
{
	int	status;

	close(pfd[0]);
	close(pipex->outfd);
	dup2(pipex->infd, STDIN);
	dup2(pfd[1], STDOUT);
	status = execve(pipex->cmd1[0], pipex->cmd1, NULL);
	close_pipe((int []){pipex->infd, pfd[1]});
}

void	ft_parent(t_pipex *pipex, int *pfd)
{
	int status;

	close(pfd[1]);
	close(pipex->infd);
	dup2(pfd[0], STDIN);
	dup2(pipex->outfd, STDOUT);
	status = execve(pipex->cmd2[0], pipex->cmd2, NULL);
	close_pipe((int []){pipex->outfd, pfd[0]});
	wait(NULL);
}

void	ft_start(t_pipex *pipex)
{
	int	pfd[2];
	int	pid;
	
	if (pipe(pfd) == -1)
		return (error_msg(8), ft_exit(pipex));
	pid = fork();
	if (pid == -1)
		return (close_pipe(pfd), error_msg(9), ft_exit(pipex));
	if (pid == 0)
		ft_chiled(pipex, pfd);
	else
		ft_parent(pipex, pfd);
}