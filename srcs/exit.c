/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:50:59 by wimam             #+#    #+#             */
/*   Updated: 2025/03/06 13:01:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	free_all(t_pipex *pipex)
{
	close(pipex->infd);
	close(pipex->outfd);
	free(pipex);
}

void	ft_exit(t_pipex *pipex)
{
	int	code;

	code = WEXITSTATUS(pipex->exit_code);
	free_all(pipex);
	exit(code);
}
