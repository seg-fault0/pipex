/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/02/19 00:15:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;

	if (argc != 5)
		return (error_msg(1), 1);
	pipex = pipex_init(--argc, ++argv);
	if (!pipex)
		return (1);
	ft_start(pipex, pipex->infd);
	if (access(pipex->cmd[pipex->count - 1][0], X_OK))
		ft_exit(pipex, 127);
	ft_exit(pipex, 0);
	return (0);
}
