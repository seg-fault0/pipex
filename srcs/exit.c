/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/02/19 00:15:46 by wimam            ###   ########.fr       */
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

void	ft_exit(t_pipex *pipex, int code)
{
	close(pipex->infd);
	close(pipex->outfd);
	free_cmd(pipex->cmd);
	free(pipex);
	exit(code);
}
