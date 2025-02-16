/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/02/16 04:42:53 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char *argv[])
{
	t_pipex	*pipex;

	if (argc < 5)
		return (error_msg(1), 1);
	pipex = pipex_init(--argc, ++argv);
	if (!pipex)
		return (1);
	ft_start(pipex, pipex->infd);
	ft_exit(pipex);
	return (0);
}
