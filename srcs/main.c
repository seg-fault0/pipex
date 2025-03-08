/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/03/06 13:01:39 by wimam            ###   ########.fr       */
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
		return (0);
	ft_start(pipex);
	ft_exit(pipex);
	return (0);
}
