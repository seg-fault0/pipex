/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:55:22 by wimam             #+#    #+#             */
/*   Updated: 2025/02/19 05:24:21 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_add_path(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->cmd[i])
	{
		tmp = pipex->cmd[i][0];
		if (access(tmp, X_OK))
		{
			pipex->cmd[i][0] = ft_strjoin(BIN_PATH, pipex->cmd[i][0]);
			free(tmp);
		}
		i++;
	}
}

char	***get_cmd(int argc, char *argv[])
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
		if (!cmd[i])
			return (error_msg(5), cmd);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	get_doc_fd(int *argc, char ***argv)
{
	int		pfd[2];
	char	*line;

	if (*argc != 5)
		return (error_msg(1), -1);
	if (pipe(pfd) == -1)
		return (error_msg(8), -1);
	ft_putstr_fd("pipe heredoc> ", 1);
	line = get_next_line(0);
	while (!ft_strcmp(line, argv[0][1]))
	{
		write(pfd[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	*argc -= 2;
	*argv += 2;
	return (close(pfd[1]), pfd[0]);
}

t_pipex	*pipex_init(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(pipex));
	if (!pipex)
		return (error_msg(5), NULL);
	if (ft_strcmp("here_doc", argv[0]))
		pipex->infd = get_doc_fd(&argc, &argv);
	else
		pipex->infd = open(argv[0], O_RDONLY);
	if (pipex->infd < 0 && !access(argv[0], R_OK))
		return (free(pipex), error_msg(10), NULL);
	if (pipex->infd < 0)
		return (free(pipex), NULL);
	pipex->outfd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	if (pipex->outfd < 0)
		return (close(pipex->infd), free(pipex), error_msg(6), NULL);
	pipex->cmd = get_cmd(argc, argv);
	if (!pipex->cmd)
		return (ft_exit(pipex, 1), NULL);
	ft_add_path(pipex);
	pipex->count = 0;
	pipex->max_count = argc - 2;
	return (pipex);
}
