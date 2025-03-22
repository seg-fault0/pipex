/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/03/22 23:48:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_wait(t_pipex *pipex)
{
	int	i;
	int	id;

	i = 0;
	while (i < pipex->count)
	{
		id = pipex->children_pid[i];
		waitpid(id, &pipex->exit_code, 0);
		i++;
	}
}

void	fd_manager(t_pipex *pipex, int rfd, int wfd)
{
	if (dup2(rfd, STDIN) == -1)
	{
		free_all(pipex);
		exit(0);
	} 
	if (pipex->count == pipex->max_count - 1)
	{
		if (dup2(pipex->outfd, STDOUT) == -1)
		{
			free_all(pipex);
			exit(0);
		}
	}
	else
	{
		if (dup2(wfd, STDOUT) == -1)
		{
			free_all(pipex);
			ft_exit(0);
		}
	}
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
		ft_wait(pipex);
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
		pipex->children_pid[pipex->count] = pid;
		pipex->count++;
		ft_start(pipex, pfd[0]);
		close(pfd[0]);
		ft_wait(pipex);
	}
}
