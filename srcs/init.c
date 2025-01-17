/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/01/17 16:08:28 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	are_cmd_exe(int argc, char **argv, char ***cmd)
{
	int		i;
	char	*tmp_cmd;

	i = 0;
	while(cmd[i])
	{
		tmp_cmd = ft_strjoin("/usr/bin/", cmd[i][0]);
		if (access(tmp_cmd, X_OK) != 0)
			return (free(tmp_cmd), error_msg(4), 1);
		free(tmp_cmd);
		i++;
	}
	return (0);
}

char ***get_cmd(int argc, char *argv[])
{
	char	***cmd;
	int		i;

	cmd = malloc ((argc - 2) * sizeof(char **) + 1);
	if (!cmd)
		return (NULL);
	i = 0;
	while (i < argc - 2)
	{
		cmd[i] = ft_split(argv[i + 1], ' ');
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}//potention leak if split faild any allocation faild

t_pipex	*pipex_init(int argc, char *argv[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(pipex));
	if (!pipex)
		return (error_msg(5), NULL);
	pipex->infd = open(argv[0], O_RDONLY);
	if (pipex->infd < 0)
		return (free(pipex), error_msg(6), NULL);
	pipex->outfd = open(argv[argc-1], O_WRONLY);
	if (pipex->outfd < 0)
		return(close(pipex->infd), free(pipex), error_msg(6), NULL);
	pipex->cmd = get_cmd(argc, argv);
	if (!pipex->cmd)
		return(close(pipex->outfd), close(pipex->infd), free(pipex), NULL);
	if (are_cmd_exe(argc, argv, pipex->cmd))
		return (close(pipex->outfd), close(pipex->infd), free(pipex), NULL); //leaks : free (pipex->cmd)
	return (pipex);
}
