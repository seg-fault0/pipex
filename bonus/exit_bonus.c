/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/07 14:25:45 by wimam            ###   ########.fr       */
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
	int	i;

	i = 3;
	while (i < 1024)
		close(i++);
	free_cmd(pipex->cmd);
	free(pipex);
}

void	ft_exit(t_pipex *pipex)
{
	int	code;

	code = WEXITSTATUS(pipex->exit_code);
	free_all(pipex);
	exit(code);
}
