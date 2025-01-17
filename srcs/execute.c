/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:14:05 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 21:09:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_pross(t_pipex *pipex, int *pfd, int count)
{
	ft_putstr("hello form the first pross\n");
	close(pipex->outfd);
	close(pfd[0]);
	dup2(pipex->infd, 0);
	dup2(pfd[1], 1);
	execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
}

void	in_pross(t_pipex *pipex, int *pfd, int count)
{
	ft_putstr("hello form the in pross\n");
	close(pipex->infd);
	close(pipex->outfd);
	dup2(pfd[0], 0);
	dup2(pfd[1], 1);
	execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
}

void	last_pross(t_pipex *pipex, int *pfd, int count)
{
	ft_putstr("hello form the last pross\n");
	close(pipex->infd);
	close(pfd[1]);
	dup2(pfd[0], 0);
	dup2(pipex->outfd, 1);
	execve(pipex->cmd[count][0], pipex->cmd[count], NULL);
}

void ft_execute(t_pipex *pipex, int *pfd, int count, int max)
{
	printf("count = %d | max = %d\n", count, max);
	if (count == max - 1)
		first_pross(pipex, pfd, count);
	else if (count == 0)
		last_pross(pipex, pfd, count);
	else
		in_pross(pipex, pfd, count);
}

void	ft_pipex(t_pipex *pipex, int count, int max)
{
	int			pfd[2];
	int			pid;
	int			id;

	if (count == max)
		return ;
	if(count <= max - 1)
	{
		pid = pipe(pfd);
		id = fork();
	}
	if (id == 0)
		ft_pipex(pipex, count + 1, max);
	else
	{
		wait(NULL);
		ft_execute(pipex, pfd, count, max);
	}
}